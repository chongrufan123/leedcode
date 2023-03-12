// 点菜问题
// http://t.cn/AiYOrkXr
// Medium
#include <iostream>
#include <vector>

using namespace std;
const int MAXC = 1001;
const int MAXN = 101;


int main(){
    int C, N;
    vector<pair<int, int>> dishes;
    pair<int, int> dish;
    int dp[MAXN][MAXC];
    while(cin >> C >> N){
        C++;
        N++;
        dishes.push_back({0, 0});
        for(int i = 1; i < N; ++i){
            cin >> dish.first;
            cin >> dish.second;
            dishes.push_back(dish);
        }
        for(int i = 0; i < N; ++i){
            dp[i][0] = 0;
        }
        for(int j = 0; j < C; ++j){
            dp[0][j] = 0;
        }
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < C; ++j){
                if(j >= dishes[i].first){
                    dp[i][j] = max(dp[i - 1][j - dishes[i].first] + dishes[i].second, dp[i - 1][j]);
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        int ans = dp[0][C - 1];
        for(int i = 1; i < N; ++i){
            ans = max(dp[i][C - 1], ans);
        }
        cout << ans << endl;
    }
}