// 最大子矩阵
// https://www.nowcoder.com/practice/a5a0b05f0505406ca837a3a76a5419b3
// Hard
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

struct matrix{
    long long data;
    pair<int, int> order;
};

const int MAXN = 100;
matrix dy[MAXN][MAXN];
int a[MAXN][MAXN];

int msum(pair<int, int> x, pair<int, int> y, int mode){
    int ans = dy[y.first - 1][y.second - 1].data;
    switch (mode)
    {
    case 1:
        for(int i = x.first; i <= y.first; ++i){
            ans += a[i][y.second];
        }
        for(int i = x.second; i <= y.second; ++i){
            ans += a[y.first][i];
        }
        ans -= a[y.first][y.second];
        return ans;
    case 2:
        ans = dy[y.first][y.second - 1].data;
        for(int i = x.first; i <= y.first; ++i){
            ans += a[i][y.second];
        }
        return ans;
    case 3:
        ans = dy[y.first - 1][y.second].data;
        for(int i = x.second; i <= y.second; ++i){
            ans += a[y.first][i];
        }
        return ans;
    default:
        break;
    }
    return 0;
}

pair<int, int> max_mq(int mq1, int mq2, int mq3){
    if(mq1 > mq2){
        if(mq1 > mq3) return {mq1, 1};
        else return {mq3, 3};
    }
    else{
        if(mq2 > mq3) return {mq2, 2};
        else return {mq3, 3};
    }
    
}

int main(){
    int N;
    int n;
    while(cin >> N){
        memset(dy, 0, sizeof(dy));
        memset(a, 0, sizeof(a));
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                cin >> n;
                a[i][j] = n;
            }
        }
        for(int i = 0; i < N; ++i){
            dy[0][i].data = a[0][i];
            dy[0][i].order = {0, i};
            dy[i][0].data = a[i][0];
            dy[i][0].order = {i, 0};
        }
        
        for(int i = 1; i < N; ++i){
            for(int j = 1; j < N; ++j){
                int mq1 = (msum(dy[i - 1][j - 1].order, {i, j}, 1));
                int mq2 = (msum(dy[i][j - 1].order, {i, j}, 2));
                int mq3 = (msum(dy[i - 1][j].order, {i, j}, 3));
                
                pair<int, int> mq = max_mq(mq1, mq2, mq3);
                if(mq.first > a[i][j]){
                    dy[i][j].data = mq.first;
                    switch(mq.second){
                    case 1:
                        dy[i][j].order = dy[i - 1][j - 1].order;
                        break;
                    case 2:
                        dy[i][j].order = dy[i][j - 1].order;
                        break;
                    case 3:
                        dy[i][j].order = dy[i - 1][j].order;
                        break;
                    }
                }
                else{
                    dy[i][j].data = a[i][j];
                    dy[i][j].order = {i, j};
                }
            }
        }
        long long ans = dy[0][0].data;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(ans < dy[i][j].data) ans = dy[i][j].data;
            }
        }
        cout << ans << endl;
    }
}