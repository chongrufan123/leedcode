// 进制转换
#include <iostream>
#include <string>
#include <stack>

using namespace std;

string str_div(string num){
    int remainder = 0;
    for(int i = 0; i < num.size(); ++i){
        int current = remainder * 10 + num[i] - '0';
        num[i] = current / 2 + '0';
        remainder = current % 2;
    }
    int pos = 0;
    while(num[pos] == '0') pos++;
    return num.substr(pos);
}

int main(){
    stack<int> erjinzhi;
    string num;
    int i = 0;
    while(getline(cin, num)){
        if(num.empty()) erjinzhi.push(0);
        while(!num.empty()){
            if(int(num.back() - '0') % 2 == 1){
                erjinzhi.push(1);
                num.back()--;
            }
            else erjinzhi.push(0);
            num = str_div(num);
            // cout << num << endl;
        }
        while(!erjinzhi.empty()){
            cout << erjinzhi.top();
            erjinzhi.pop();
        }
        cout << endl;
    }
    return 0;
}