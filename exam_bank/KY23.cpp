// 最小花费
// https://www.nowcoder.com/practice/e6df3e3005e34e2598b9b565cfe797c9
// Medium
#include <iostream>

using namespace std;
const int MAXN = 100;

int L1, L2, L3, C1, C2, C3;

int cost(int a, int b){
    if(b - a == 0) return 0;
    if(b - a <= L1) return C1;
    if(b - a <= L2 && b - a > L1) return C2;
    if(b - a <= L3 && b - a > L2) return C3;
    return -1;
}

int main(){
    int n;
    int A, B;
    int a[MAXN];
    int dp[MAXN];
    while(cin >> L1 >> L2 >> L3 >> C1 >> C2 >> C3){
        cin >> A >> B;
        cin >> n;
        for (int i = 2; i < n + 1; ++i){
            cin >> a[i];
        }
        dp[A] = 0;
        dp[A+1] = cost(a[A], a[A+1]);
        for(int i = 2; i < B - A + 1; ++i){
            dp[A+i] = cost(a[A+i-1], a[A+i]) + dp[A+i-1];
            for(int j = i - 1; j >= 0; --j){
                if(a[A+i] - a[A+j] > L3) break;
                dp[A+i] = min(dp[A+i], cost(a[A + j], a[A + i]) + dp[A+j]);
            }
        }
        cout << dp[B] << endl;
    }
}
