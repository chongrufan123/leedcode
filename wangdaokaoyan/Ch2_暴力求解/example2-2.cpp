// 反序数
#include <iostream>

using namespace std;

int main(){
    int a, b, c, d; // 分别用来存储N的个位十位百位千位
    for(int ix = 1000; ix < 10000; ++ix){
        a = ix % 10;
        b = ix / 10 % 10;
        c = ix / 100 % 10;
        d = ix / 1000;
        if(ix * 9 == a * 1000 + b * 100 + c * 10 + d)
            cout << ix << endl;
    }
    return 0;
}