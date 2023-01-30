// 二进制数
#include <iostream>
#include <math.h>
#include <stack>

using namespace std;

int main(){
    stack<int> erjinzhi;
    int num;
    int i = 0;
    while(cin >> num){
        if(num < 0) break;
        while(num != 0){
            if(num % 2 == 1){
                erjinzhi.push(1);
                num = num - pow(2, i);
            }
            else erjinzhi.push(0);
            num /= 2;
        }
        while(!erjinzhi.empty()){
            cout << erjinzhi.top();
            erjinzhi.pop();
        }
        cout << endl;
    }
    return 0;
}