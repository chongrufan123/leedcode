// 连通图
// http://t.cn/Ai077VoA
// Medium

#include <iostream>

using namespace std;
const int MAXN = 1005;
int tab[MAXN];

void init_tab(int n){
    for(int i = 1; i <= n; ++i){
        tab[i] = i;
    }
}

int father(int a){
    if(tab[a] == a) return a;
    else return father(tab[a]);
}

void merge(int a, int b){
    tab[father(b)] = father(a);
}

bool check_tab(int n){
    int root = father(1);
    for(int i = 2; i <= n; ++i){
        if(father(i) != root) return false;
    }
    return true;
}

int main(){
    int n, m;
    int a, b;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        init_tab(n);
        while(m--){
            cin >> a >> b;
            if(father(a) == father(b)) continue;
            else(merge(a, b));
        }
        if(check_tab(n)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}