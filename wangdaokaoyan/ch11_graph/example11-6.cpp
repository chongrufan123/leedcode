// 畅通工程续
// 
// 
#include <iostream>
#include <queue>

using namespace std;
const int MAXN = 205;
const int MAXM = 1005;
const int INF = 0x7fffffff;
int dis[MAXN];
bool vis[MAXN];
int N, M;
int start, en;

struct road{
    int a;
    int b;
    int distance;
    bool operator<(const road& r) const {
        return distance > r.distance;
    }
};
road ro[MAXM * 2];
void Dijkstra(){
    priority_queue<road> rq;
    for(int i = 0; i < N; ++i){
        dis[i] = INF;
        vis[i] = false;
    }
    dis[start] = 0;
    vis[start] = true;
    rq.push(ro[0]);
    while(!vis[en]){
        int current = -1;
        for(int i = 0; i < 2 * M; ++i){
            // cout << "test" << endl;
            if(dis[ro[i].b] > ro[i].distance + dis[start]){
                dis[ro[i].b] = ro[i].distance + dis[ro[i].a];
                rq.push(ro[i]);
            }
            if(current == -1 || dis[current] > dis[ro[i].b]){
                if(!vis[ro[i].b]){
                    current = ro[i].b;
                }
            }
        }
        if(current != -1){
            vis[current] = true;
            start = current;
        }else break;
    }
    if(!vis[en]) cout << "-1" << endl;
    else cout << dis[en] << endl;
}

int main(){
    while(cin >> N >> M){
        for(int i = 0; i < M; ++i){
            cin >> ro[i].a >> ro[i].b >> ro[i].distance;
            ro[M + i].a = ro[i].b;
            ro[M + i].b = ro[i].a;
            ro[M + i].distance = ro[i].distance;
        }
        cin >> start >> en;
        Dijkstra();
    }
}