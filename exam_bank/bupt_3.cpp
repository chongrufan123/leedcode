// 树查找
// https://www.nowcoder.com/practice/9a10d5e7d99c45e2a462644d46c428e4
// Hard
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n;
    vector<pair<int, int> > vp;
    pair<int, int> p;
    int deep;
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> p.first;
            for(int d = 0; ; d++){
                if(i+1 >= 1 << d && i+1 < 1 << (d+1)){
                    p.second = d+1;
                    break;
                }
            }
            vp.push_back(p);
        }
        cin >> deep;
        while(!vp.empty()){
            if(vp.front().second == deep){
                cout << vp.front().first;
                vp.erase(vp.begin());
                if(vp.front().second == deep) cout << " ";
                else {
                    vp.erase(vp.begin(), vp.end());
                    cout << endl;
                }
            }
            else{
                vp.erase(vp.begin());
                if(vp.empty()) {
                    cout << "EMPTY";
                    cout << endl;
                }
            }
        }
    }
    return 0;
}