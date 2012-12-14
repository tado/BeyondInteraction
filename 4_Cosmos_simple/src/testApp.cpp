#include "testApp.h"

#include "fft.h"

float *audio_input = NULL;

float *magnitude, *phase, *power;
float *magnitude_average, *magnitude_average_snapshot; 
float *circle_phase;
const int buffer_size = 1024, fft_size = 512;

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
	
	circle_phase = new float[fft_size];
	
	for (int i = 0; i < fft_size; i++)
	{
		magnitude[i] = 0;
		phase[i] = 0;
		power[i] = 0;
		magnitude_average_snapshot[i] = 0;
		magnitude_average[i] = 0;
	}
	
	// オーディオインプットを初期化
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
		//  環境ノイズをキャンセル
		float v = fabs(magnitude_average[i] - magnitude_average_snapshot[i]);
		
		v *= 0.1;
		
		// 円の回転角(0.0 ~ 1.0)を更新
		circle_phase[i] += v;
		while (circle_phase[i] > 1) circle_phase[i] -= 1;
	}
}

void testApp::draw()
{
	// 背景は黒
	ofBackground(0, 0, 0);
	
	// 視点の調整
	glTranslatef(ofGetWidth()/2, ofGetHeight()/2 + 100, 0);
	glRotatef(50, 1,0,0);
	glTranslatef(0,0, 200);
	
	ofSetColor(255,255,255);
	
	for (int i = 0; i < fft_size; i++)
	{
		// 円の回転角からXY座標を算出、iの値を半径の長さに反映させる
		float xx = cos(TWO_PI * circle_phase[i]) * i;
		float yy = sin(TWO_PI * circle_phase[i]) * i;
		
		// 円を描画
		ofCircle(xx, yy, 2);
	}
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
