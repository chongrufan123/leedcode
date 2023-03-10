// N阶楼梯上楼问题
// http://t.cn/Aij9Fr3V
// Hard
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 90;
int a[MAXN];

int up(int N){
    if(N == 1) return 1;
    if(N == 2) return 2;
    else{
        return (a[N - 3] + a[N - 2]);
    }
}

int main(){
    int N;
    while(cin >> N){
        memset(a, 0, sizeof(a));
        for(int i = 0; i < N; ++i){
            a[i] = up(i + 1);
        }
        cout << a[N - 1] << endl;
    }
    return 0;
}