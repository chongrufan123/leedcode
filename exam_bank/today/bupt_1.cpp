// 查找第K小数
// https://www.nowcoder.com/practice/204dfa6fcbc8478f993d23f693189ffd
// Hard
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> q;
    int n, k;
    int num;
    vector<int> v;
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> num;
            if(find(v.begin(), v.end(), num) != v.end()) continue;
            v.push_back(num);
            q.push(num);
        }
        cin >> k;
        for(int i=0; i<k-1; ++i){
            q.pop();
        }
        cout << q.top() << endl;
        while(!q.empty()) q.pop();
        v.erase(v.begin(), v.end());
    }
    return 0;
}