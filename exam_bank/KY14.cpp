// 最小邮票数
// https://www.nowcoder.com/practice/83800ae3292b4256b7349ded5f178dd1
// Hard
#include<iostream>
#include<vector>

using namespace std;

int getCnt(int m, vector<int>& stamps, int index, int cnt){
    if(m == 0) return cnt;
    int ans = 20;
    //下一张邮票可能取 index ~ 0 中的某一张
    for(int i = index; i >= 0; i --){
        if(m == stamps[i]) ans = min(ans, cnt + 1);
        //如果邮票面额大于要凑齐的总值，自然不需要去选
        if(m > stamps[i]){
            int newCnt = getCnt(m - stamps[i], stamps, i - 1, cnt + 1);
            if(newCnt != 0){
                ans = min(ans, newCnt);
            }
        }
    }
    return ans == 20 ? 0 : ans;
}

int main(){
    int m, n;
    while(cin >> m >> n){
        vector<int> stamps(n);
        for(int i = 0; i < n; i ++)
            cin >> stamps[i];
        cout << getCnt(m, stamps, n - 1, 0) << endl;
    }
}
