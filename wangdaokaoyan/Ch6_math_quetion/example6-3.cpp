// 十进制与二进制
#include <iostream>
#include <stack>
#include <math.h>

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

string str_sum(string &num, int x){ // 字符串加法
    int carry = x;
    for(int i = num.size() - 1; i >= 0; --i){
        int current = (num[i] - '0') + carry;
        num[i] = current % 10 + '0';
        carry = current / 10;
    }
    if(carry != 0){
        num = "1" + num;
    }
    return num;
}

int main(){
    stack<int> bin;
    string num;
    int i = 0;
    getline(cin, num);
    if(num.empty()) bin.push(0);
    while(!num.empty()){
        if(int(num.back() - '0') % 2 == 1){
            bin.push(1);
            num.back()--;
        }
        else bin.push(0);
        num = str_div(num);
        // cout << num << endl;
    }
    for(int i = 0; !bin.empty(); ++i){
        // cout << bin.top();
        if(bin.top() == 1)
            num = str_sum(num, pow(2, i));
        bin.pop();
    }
    // cout << endl;
    cout << num << endl;

    return 0;

}
