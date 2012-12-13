#include <iostream>
using namespace std;

class Dog { // Dogクラスの定義
public:
    string name; //犬の名前 (状態)
    void bark(); //犬が吠える (動作)
}; //Dogクラスの定義終了 (最後に";"が入るのに注意)

void Dog::bark() { //Dogのメソッド bark() の定義
    //プログラムのデータ出力に、名前と鳴き声を表示
    cout << name << "「ワンワン!」" << endl;
}

int main (int argc, char * const argv[]) { //メイン関数
    Dog hachi; //Dogクラスをインスタンス化して、hachiを生成
    hachi.name = "ハチ"; //hachiのプロパティnameに"ハチ"を代入
    hachi.bark(); //hachiのメソッドbark()を実行
}