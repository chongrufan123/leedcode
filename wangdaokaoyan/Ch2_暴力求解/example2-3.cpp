// 对称平方数1
#include <iostream>

using namespace std;

int Reverse(int ix){    // 将ix反序
    int x = 0;
    while(ix != 0){
        x = x * 10 + ix % 10;
        ix/=10;
    }
    return x;
}

int main(){
    for(int ix = 0; ix < 256; ++ix){
        if(ix * ix == Reverse(ix * ix))
            cout << ix << endl;
    }

    return 0;
}