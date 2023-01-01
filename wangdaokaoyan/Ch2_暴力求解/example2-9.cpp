// 剩下的树
#include <iostream>
#include <vector>
using namespace std;

int main(){
    int L;
    int M;
    int a, b;
    int count = 0;
    cin >> L >> M;
    vector<bool> tree(L + 1, true);
    while(M-- > 0){
        cin >> a >> b;
        fill(tree.begin() + a, tree.begin() + b + 1, false);
    }

    for(int i = 0; i < tree.size(); ++i){
        if(tree[i]) count++;
    }

    cout << count;

    return 0;
}