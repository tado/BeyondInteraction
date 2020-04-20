#include "Dog.h"

int main (int argc, char * const argv[]) { //メイン関数
    Dog hachi; //Dogクラスをインスタンス化して、hachiを生成
    hachi.name = "ハチ"; //hachiのプロパティnameに"ハチ"を代入
    hachi.bark(); //hachiのメソッドbark()を実行
}