// 最小公倍数
#include <iostream>

using namespace std;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int beishu(int a, int b){
    int max_num = max(a, b);
    while(true){
        if(max_num % a == 0 && max_num % b == 0) return max_num;
        max_num ++;
    }
}

int main(){
    int a, b;
    int res;
    while(cin >> a >> b){
        res = beishu(a, b);
        cout << res << endl;
    }

    return 0;
}