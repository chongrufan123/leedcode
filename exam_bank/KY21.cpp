// 递推数列
// https://www.nowcoder.com/practice/d0e751eac618463bb6ac447369e4aa25
// Hard
#include <iostream>

using namespace std;

const int MAXK = 100001;

int main(){
    int a0, a1, p, q, k;
    int dp[MAXK];
    cin >> a0 >> a1 >> p >> q >> k;
    dp[0] = a0;
    dp[1] = a1;
    for(int i = 2; i < k + 1; ++i){
        dp[i] = (p * dp[i - 1] + q * dp[i - 2])%10000;
    }
    cout << dp[k] << endl;
}