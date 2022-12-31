// 百鸡问题
#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    for(int x = 0; x <= 100; ++x){
        for(int y = 0; y <= 100 - x; ++y){
            if(x * 5 + y * 3 + (100 - x - y) * 0.33333 <= n){
                cout << "x=" << x << ",y=" << y << ",z=" << 100 - x - y << endl; 
            }
        }
    }
    return 0;
}