// 简单计算器
#include <iostream>
#include <stack>
#include <string>

using namespace std;

void cal(stack<char> &symbol, stack<float> &num){
    float a, b;
    if(symbol.top() == '*'){
        symbol.pop();
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a * b);
    }else if(symbol.top() == '/'){
        symbol.pop();
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(b / a);
    }else if(symbol.top() == '+'){
        symbol.pop();
        a = num.top();
        num.pop();
        b = num.top();
        num.pop();
        num.push(a + b);
    }else if(symbol.top() == '-'){
        symbol.pop();
        a = num.top();
        num.pop();
        b = num.top();
        // cout << "a = " << a << "  b = " << b << " " << endl;
        num.pop();
        num.push(b - a);
    }
}

float getNum(string str, int &index){
    float number = 0;
    while(str[index] >= '0' && str[index] <= '9'){
        number = number * 10 + (str[index] - '0');
        index++;
    }
    return number;
}

int main(){
    string str;
    stack<float> num;
    stack<char> symbol;
    int a, b;

    while(getline(cin, str)){
        if(str == "0") return 0;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] == ' ') continue;
            if(str[i] == '+' || str[i] == '-'){
                if(!symbol.empty()){
                    // if(symbol.top() == '*' || symbol.top() == '/'){
                    cal(symbol, num);
                    // }
                }
                symbol.push(str[i]);
                
            }else if(str[i] == '*' || str[i] == '/'){
                if(!symbol.empty() && (symbol.top() == '*' || symbol.top() == '/'))
                    cal(symbol, num);
                symbol.push(str[i]);
            }else{
                num.push(getNum(str, i));
            }
        }
        while(!symbol.empty()){
            cal(symbol, num);
        }
        printf("%.2f\n", num.top());
        num.pop();
    }
    return 0;
}