// 查找
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n, N;
    int m;
    int x;
    int pos;
    while(cin >> n){
        N = n;
        vector<int> a;
        while(n--){
            cin >> x;
            a.push_back(x);
        }
        cin >> m;
        while(m--){
            cin >> x;
            pos = find(a.begin(), a.end(), x) - a.begin();
            if(pos >= N) cout << "NO" << endl;
            else cout << "YES" << endl; 
        }
        a.erase(a.begin(), a.end());
    }
    return 0;
}