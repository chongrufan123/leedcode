// 放苹果
// https://www.nowcoder.com/practice/4f0c1e21010e4d849bde5297148e81d9
// Easy
#include <iostream>

using namespace std;

int const MAXN = 11;
int const MAXM = 11;

int main(){
    int M, N;   // M为苹果数，N为盘子数
    int dp[MAXN][MAXM];
    while(cin >> M >> N){
        for(int i = 1; i <= M; ++i){
            dp[1][i] = 1;
            dp[0][i] = 1;
        }
        for(int i = 1; i <= N; ++i){
            dp[i][1] = 1;
            dp[i][0] = 1;
        }
        for(int i = 2; i <= N; ++i){
            for(int j = 2; j <= M; ++j){
                // cout << "i="<< i << "\t j=" << j << endl;
                if(i > j) dp[i][j] = dp[i-1][j];
                else{
                    dp[i][j] = dp[i][j-i] + dp[i-1][j];
                }
            }
        }
        cout << dp[N][M] << endl;
    }
}