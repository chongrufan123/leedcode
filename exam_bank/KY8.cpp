// 整数拆分
// https://www.nowcoder.com/practice/376537f4609a49d296901db5139639ec
// Medium

#include <iostream>
#include <cstring>

using namespace std;

int num = 0;
const int MAXN = 1000001;
long long unsigned dp[MAXN];

int main(){
    int N;
    int top = 2;
    memset(dp, 0, sizeof(dp));
    while(cin >> N){
        num = 0;
        if(dp[N] != 0){
            cout << dp[N] << endl;
            continue;
        }
        dp[1] = 1;
        for(int i = top; i <= N; ++i){
            if(i % 2 != 0) dp[i] = dp[i-1];
            else{
                dp[i] = (dp[i-1] + dp[i/2]) % 1000000000;
            }
        }
        top = N + 1;
        cout << dp[N]  << endl;
    }
}