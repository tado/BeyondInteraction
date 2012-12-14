#include "testApp.h"

#include "fft.h"

float *audio_input = NULL;

float z_offset = 0, z_offset_t = z_offset;
float d_offset = 10, d_offset_t = d_offset;
bool show_ring = true;
float ring_effect_alpha = 0;
bool show_line = false;
float line_effect_alpha = 0;

float *magnitude, *phase, *power;
float *magnitude_average, *magnitude_average_snapshot; 
float *ring_phase, *ring_phase_delta;
int buffer_size = 1024, fft_size = 512;

fft myfft;

void testApp::setup(){
	// フレームレートを60Hzにセット
	ofSetFrameRate(60);
	ofSetVerticalSync(true);
	
	// アルファブレンディング & スムーシングを有効化
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	
	// もろもろの配列を生成&初期化
	audio_input = new float[buffer_size];
	magnitude = new float[fft_size];
	phase = new float[fft_size];
	power = new float[fft_size];
	
	magnitude_average = new float[fft_size];
	magnitude_average_snapshot = new float[fft_size];
	
	ring_phase = new float[fft_size];
	ring_phase_delta = new float[fft_size];

	for (int i = 0; i < fft_size; i++)
	{
		magnitude[i] = 0;
		phase[i] = 0;
		power[i] = 0;
		magnitude_average_snapshot[i] = 0;
		magnitude_average[i] = 0;
	}
	
	// オーディオインプットを指定
	ofSoundStreamSetup(0, 1, this, 44100, buffer_size, 4);
}

void testApp::audioReceived(float* input, int bufferSize, int nChannels)
{
	// 入力された音声シグナルを audio_input にコピー
	memcpy(audio_input, input, sizeof(float) * bufferSize);
	
	float avg_power = 0.0f;
	
	// アドオンのFFTクラスを使ってスペクトルを解析、 magnitude が欲しかったFFT振幅の値になる。
	myfft.powerSpectrum(0, (int)fft_size, audio_input, buffer_size, 
						magnitude, phase, power, &avg_power);
	
	// 結果の値の大小が激しかったので平方根をとった
	for (int i = 0; i < fft_size; i++)
	{
		magnitude[i] = powf(magnitude[i], 0.5);
	}
}


void testApp::keyPressed(int key){
	// 半径の大きさをトグル
	if (key == '1')
	{
		d_offset_t = d_offset_t == 2 ? 20 : 2;
	}
	
	// 円錐状に整列
	if (key == '2')
	{
		z_offset_t = z_offset_t == 0 ? 1 : 0;
	}
	
	// 線フェクトをトグル
	if (key == 'a')
	{
		show_ring = show_ring ? false : true;
	}
	
	// 残像エフェクトをトグル
	if (key == 's')
	{
		show_line = show_line ? false : true;
	}
	
	// スペースキーを押したときにFFT振幅平均値のスナップショットをコピー
	if (key == ' ')
	{
		memcpy(magnitude_average_snapshot, magnitude_average, sizeof(float) * fft_size);
	}
}

void testApp::update()
{
	// FFT振幅の平均値を計算
	for (int i = 0; i < fft_size; i++)
	{
		float x = 0.025;
		magnitude_average[i] = (magnitude[i] * x) + (magnitude_average[i] * (1 - x));
	}
	
	for (int i = 0; i < fft_size; i++)
	{
		float v = fabs(magnitude_average[i] - magnitude_average_snapshot[i]);
		
		v *= 0.1;
		
		// 円の位置の元になっている値(0.0 ~ 1.0)を更新
		ring_phase[i] += v;
		while (ring_phase[i] > 1) ring_phase[i] -= 1;
		
		// エフェクトのためのFFTスペクトルの変化量を更新
		ring_phase_delta[i] = v * 0.05;
	}
	
	// 視点やエフェクトのアルファ値などを更新
	d_offset += (d_offset_t - d_offset) * 0.001;
	z_offset += (z_offset_t - z_offset) * 0.001;
	line_effect_alpha += ((show_line ? 1.0 : 0.0) - line_effect_alpha) * 0.01;
	ring_effect_alpha += ((show_ring ? 1.0 : 0.0) - ring_effect_alpha) * 0.01;
}

void testApp::draw()
{
	// 背景は黒
	ofBackground(0, 0, 0);
	
	glPushMatrix();
	
	// 視点の調整
	glTranslatef(ofGetWidth()/2, ofGetHeight()/2 + 100, 0);
	glRotatef(50, 1,0,0);
	glTranslatef(0,0, 200);
	
	float zz = 0;
	for (int i = 0; i < fft_size; i++)
	{
		float xx = cos(TWO_PI * ring_phase[i]) * i * d_offset;
		float yy = sin(TWO_PI * ring_phase[i]) * i * d_offset;
		
		glColor4f(1,1,1, 1);

		glPushMatrix();
		// 円錐状に配置
		glTranslatef(0, 0, zz);
		ofCircle(xx, yy, 2);
		glPopMatrix();
		
		zz -= z_offset;
	}

	// インデックス順に線をひくエフェクト
	if (line_effect_alpha > 0.001)
	{
		float zz = 0;
		glPushMatrix();
		glBegin(GL_LINE_STRIP);
		
		for (int i = 0; i < fft_size; i++)
		{
			float xx = cos(TWO_PI * ring_phase[i]) * i * d_offset;
			float yy = sin(TWO_PI * ring_phase[i]) * i * d_offset;
			float a = powf(ring_phase_delta[i] * 1000, 1.9) * line_effect_alpha;
			
			glColor4f(1,1,1, a);

			glVertex3f(xx,yy,zz);
			zz -= z_offset;
		}
		
		glEnd();
		glPopMatrix();
	}
	
	// 残像のようなエフェクト
	if (ring_effect_alpha > 0.001)
	{
		float zz = 0;
		glPushMatrix();
		
		for (int i = 0; i < fft_size; i++)
		{
			glBegin(GL_LINE_STRIP);
			for (int n = 0; n < 20; n++)
			{
				float xx = cos(TWO_PI * (ring_phase[i] - n * 0.02)) * i * d_offset;
				float yy = sin(TWO_PI * (ring_phase[i] - n * 0.02)) * i * d_offset;
				float d = 1 - ((float)n / 20.0);
				float a = powf(ring_phase_delta[i] * 1000 * d, 1.2) * ring_effect_alpha;
				
				glColor4f(1,1,1, a);
				
				glVertex3f(xx,yy,zz);
			}
			glEnd();
			
			zz -= z_offset;
		}
		
		glPopMatrix();
	}
	
	glPopMatrix();
}

void testApp::keyReleased(int key){

}

void testApp::mouseMoved(int x, int y){

}

void testApp::mouseDragged(int x, int y, int button){

}

void testApp::mousePressed(int x, int y, int button){

}

void testApp::mouseReleased(int x, int y, int button){

}

void testApp::windowResized(int w, int h){

}
