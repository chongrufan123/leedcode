// 小白鼠排队
// https://www.nowcoder.com/practice/27fbaa6c7b2e419bbf4de8ba60cf372b
// Easy
#include <iostream>
#include <queue>

using namespace std;

struct mouse{
    int weight;
    string color;
    bool operator<(mouse const &m) const{
        return weight < m.weight;
    }
    mouse(int wei, string col) : weight(wei), color(col) {}
};

int main(){
    priority_queue<mouse> qm;
    int n;
    int wei;
    string col;
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> wei >> col;
            qm.push(*(new mouse(wei, col)));
        }
        while(!qm.empty()){
            cout << qm.top().color << endl;
            qm.pop();
        }
    }
    return 0;
}