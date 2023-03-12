// Common Subsequence
// 
// 
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 101;

int main(){
    string in1, in2;
    int dp[MAXN][MAXN];
    while(true){
        memset(dp, 0, sizeof(dp));
        cin >> in1;
        cin >> in2;
        for(int i = 0; i < in1.length(); ++i){
            if(in1[i] == in2[0]) dp[i][0] = 1;
        }
        for(int i = 0; i < in2.length(); ++i){
            if(in1[0] == in2[i]) dp[0][1] = 1;
        }
        for(int i = 1; i < in1.length(); ++i){
            for(int j = 1; j < in2.length(); ++j){
                if(in1[i] == in2[j]){
                    dp[i][j] = 1;
                    for(int k = 0; k < i; ++k){
                        for(int l = 0; l < j; ++l){
                            dp[i][j] = max(dp[k][l] + 1, dp[i][j]);
                        }
                    }
                }
            }
        }
        int ans = dp[0][0];
        for(int i = 0; i < in1.length(); ++i){
            for(int j = 0; j < in2.length(); ++j){
                ans = max(ans, dp[i][j]);
            }
        }
        cout << ans << endl;
        
    }
}