// 继续畅通工程
// http://t.cn/AiW3fcfp
// Medium
#include <iostream>
#include <queue>

using namespace std;

const int MAXN = 5005;
const int MAXG = 105;

int tab[MAXG];

void init_tab(int n){
    for(int i = 1; i <= n; ++i){
        tab[i] = i;
    }
}

int father(int i){
    if(tab[i] == i) return i;
    else return father(tab[i]);
}

void merge(int a, int b){
    tab[father(b)] = father(a);
}

bool check_in(int n){
    int a = tab[1];
    for(int i = 2; i <= n; ++i){
        if(father(i) != a){
            return false;
        }
    }
    return true;
}

struct road{
    int a;
    int b;
    int distance;
    bool statu;
    bool operator<(const road& r) const{
        if(statu == 1) return false;
        if(r.statu == 1) return true;
        return distance > r.distance;
        }
};

int main(){
    int N;
    road r;
    priority_queue<road> roadq;
    while(cin >> N){
        if(N == 0) break;
        int num = 0;
        for(int i = 0; i < N * (N - 1) / 2; ++i){
            cin >> r.a >> r.b >> r.distance >> r.statu;
            roadq.push(r);
        }
        init_tab(N);
        while(!roadq.empty()){
            r = roadq.top();
            if(r.statu == 1){
                merge(r.a, r.b);
                roadq.pop();
                continue;
            }
            if(father(r.a) == father(r.b)){
                roadq.pop();
                continue;
            }
            merge(r.a, r.b);
            num += r.distance;
            roadq.pop();
        }
        cout << num << endl;
    }
    return 0;
}