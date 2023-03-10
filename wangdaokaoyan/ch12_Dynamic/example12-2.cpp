// 最大序列和
// http://t.cn/AiYS1QMU
// Medium
#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int MAXN = 1000001;

long long dp[MAXN];

int max_int(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int N;
    vector<int> num;
    int a;
    while(cin >> N){
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < N; ++i){
            cin >> a;
            num.push_back(a);  
        }
        dp[0] = num[0];
        for(int i = 1; i < N; ++i){
            dp[i] = max_int(dp[i - 1] + num[i], num[i]);
        }
        int ans = dp[0];
        for(int i = 0; i < N; ++ i){
            if(ans < dp[i]) ans = dp[i];
        }
        cout << ans << endl;
        num.erase(num.begin(), num.end());
    }
}