// 输出梯形
#include <iostream>
using namespace std;

int main(){
    int h;
    cin >> h;
    for(int i = 0; i < h; ++i){
        for(int j = 0; j <= h + (h - 1) * 2; ++j){
            if( j <= (h - 1) * 2 - i * 2) cout << " ";
            else cout << "*";
        }
        cout << endl;
    }
    return 0;
}