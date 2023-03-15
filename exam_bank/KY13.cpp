// 求最大最小数
// https://www.nowcoder.com/practice/82e5ff335eeb486aab359767895cc7b4
// Medium

#include <iostream>
#include <queue>

using namespace std;

int main(){
    int N;
    priority_queue<int> maxq;
    priority_queue<int, vector<int>, greater<int>> minq;
    int n;
    while(cin >> N){
        for(int i = 0; i < N; ++i){
            cin >> n;
            maxq.push(n);
            minq.push(n);
        }
        cout << maxq.top() << " " << minq.top() << endl;
        while(!maxq.empty()) maxq.pop();
        while(!minq.empty()) minq.pop();
    }
}