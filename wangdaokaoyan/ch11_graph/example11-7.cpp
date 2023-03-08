// 最短路径问题
// http://t.cn/AilPbME2
// Hard

#include <iostream>
#include <queue>
#include <string>

using namespace std;

struct road{
    int a;
    int b;
    int distance;
    int cost;
    bool operator<(const road& r) const{
        if(distance != r.distance) return distance > r.distance;
        else return cost > r.cost;
    }
};

const int MAXN = 1005;
const int MAXM = 100000;
road ro[2 * MAXM];
int s, e;
int n, m;


void Dijstra(){
    int cos[MAXN];
    int dis[MAXN];
    bool vis[MAXN];
    for(int i = 1; i <= n; ++i){
        cos[i] = -1;
        dis[i] = -1;
        vis[i] = false;
    }
    dis[s] = 0;
    cos[s] = 0;
    vis[s] = true;
    while(!vis[e]){
        int content = -1;
        for(int i = 0; i < 2 * m; ++i){
            if(ro[i].a == s){
                if(dis[ro[i].b] == -1 || dis[ro[i].b] > dis[s] + ro[i].distance){
                    dis[ro[i].b] = dis[s] + ro[i].distance;
                    cos[ro[i].b] = cos[s] + ro[i].cost;
                }
                if(dis[ro[i].b] == dis[s] + ro[i].distance){
                    if(cos[ro[i].b] > cos[s] + ro[i].cost)
                        cos[ro[i].b] = cos[s] + ro[i].cost;
                }
                if(content == -1 || dis[content] > dis[ro[i].b]){
                    if(!vis[ro[i].b])
                        content = ro[i].b;
                }
            }
        }
        if(content != -1){
            s = content;
            vis[s] = true;
        }else break;
    }
    cout << dis[e] << " " << cos[e] << endl;
}

int main(){
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0; i < m; ++i){
            cin >> ro[i].a >> ro[i].b >> ro[i].distance >> ro[i].cost;
            ro[m + i].a = ro[i].b;
            ro[m + i].b = ro[i].a;
            ro[m + i].distance = ro[i].distance;
            ro[m + i].cost = ro[i].cost;
        }
        cin >> s >> e;
        Dijstra();
    }
}