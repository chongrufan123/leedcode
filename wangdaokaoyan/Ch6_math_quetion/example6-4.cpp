// 进制转换2
#include <iostream>
#include <cctype>
#include <stack>
#include <math.h>

using namespace std;

long long M_to_dec(string X, int M){
    long long num = 0;
    for(int i = X.size() - 1; i >= 0; --i){
        if(isdigit(X[i]))
            num += (int(X[i] - '0') * pow(M, (X.size() - i - 1)));
        else if(isupper(X[i]))
            num += (int(X[i] - 'A') * pow(M, (X.size() - i - 1)));
    }
    return num;
}

string dec_to_N(long long dec, int N){
    string res;
    stack<int> num;
    int temp;
    while(dec != 0){
        temp = dec % N;
        if(temp < 10) num.push(temp + '0');
        else if(temp > 9) num.push(temp - 10 + 'a');
        dec /= N;
    }
    while(!num.empty()){
        res.insert(res.end(), num.top());
        num.pop();
    }
    return res;
}

int main(){
    int M, N;
    string X;
    long long dec;
    cin >> M >> N;
    cin >> X;
    dec = M_to_dec(X, M);

    cout << dec_to_N(dec, N);

    return 0;
}