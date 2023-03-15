// 中位数
// https://www.nowcoder.com/practice/2364ff2463984f09904170cf6f67f69a
// Medium
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;
    int x;
    int n;
    while(cin >> n){
        if(n == 0) return 0;
        for(int i = 0; i < n; ++i){
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        if(n % 2 == 0) cout << (v[n/2] + v[n/2 - 1]) / 2 << endl;
        else cout << v[n/2] << endl;
        v.clear();
    }
}