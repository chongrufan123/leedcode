// 特殊算法
#include <iostream>
#include <string>
using namespace std;

int main(){
    string x, y;
    int sum = 0;
    while(cin >> x >> y){
        for(int i = 0; i < x.size(); ++i){
            for(int j = 0; j < y.size(); ++j){
                sum += int(x[i] - '0') * int(y[j] - '0');
            }
        }
        cout << sum << endl;
        sum = 0;
        x.erase(x.begin(), x.end());
        y.erase(y.begin(), y.end());
    }
    return 0;
}