// 确定比赛名次
// 
// 
#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

const int MAXN = 505;

vector<int> graph[MAXN];
int de[MAXN];

void rank_sort(int n){
    vector<int> topology;
    priority_queue<int, vector<int>, greater<int> > node;
    for(int i = 1; i <= n; ++i){
        if(de[i] == 0) node.push(i);
    }
    while(!node.empty()){
        int u = node.top();
        node.pop();
        topology.push_back(u);
        for(int i = 0; i < graph[u].size(); ++i){
            de[graph[u][i]] --;
            if(de[graph[u][i]] == 0)
                node.push(graph[u][i]);
        }
    }
    while(!topology.empty()){
        cout << topology.front();
        topology.erase(topology.begin());
        if(topology.empty()) break;
        else cout << " ";
    }

}

int main(){
    int n, m;
    int a, b;
    while(cin >> n >> m){
        memset(graph, 0, sizeof(graph));
        memset(de, 0, sizeof(de));
        while(m --){
            cin >> a >> b;
            graph[a].push_back(b);
            de[b]++;
        }
        rank_sort(n);
    }
}