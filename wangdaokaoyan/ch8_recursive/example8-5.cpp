// 二叉树
#include <iostream>
#include <queue>

using namespace std;

int func(int m, int n){
    if(m > n) return 0;
    return func(m * 2, n) + func(m * 2 + 1, n) + 1;
}

int main(){
    int n, m;
    while(cin >> m >> n){
        if(n == 0 && m == 0) return 0;
        cout << func(m, n) << endl;
    }
    return 0;
}