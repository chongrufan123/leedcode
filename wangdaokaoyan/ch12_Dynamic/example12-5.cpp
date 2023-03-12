// 最大上升子序列和
// http://t.cn/AiYNAGD3
// Easy
#include <iostream>

using namespace std;
const int MAXN = 1001;

int main(){
    int N;
    int a[MAXN];
    int dy[MAXN];
    while(cin >> N){
        for(int i = 0; i < N; ++i){
            cin >> a[i];
        }
        dy[0] = a[0];
        for(int i = 1; i < N; ++i){
            dy[i] = a[i];
            for(int j = 0; j < i; ++j){
                if(a[i] > a[j]){
                    dy[i] = max(dy[j] + a[i], dy[i]);
                }
            }
        }
        int ans = dy[0];
        for(int i = 1; i < N; ++i){
            ans = max(dy[i], ans);
        }
        cout << ans << endl;
    }
    return 0;
}