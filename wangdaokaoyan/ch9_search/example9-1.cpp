#include <iostream>
#include <queue>

using namespace std;

int level_search(int n, int k){
    int count = 0;
    int right = n;
    int num;
    queue<int> q;
    q.push(n);
    while(!q.empty()){
        num = q.front();
        if(k == num){
            return count;
        }
        if(num == right){
            count ++;
            right *= 2;
        }
        if(num - 1 >= 0) q.push(num - 1);
        if(num + 1 <= 100000) q.push(num + 1);
        if(num * 2 <= 100000) q.push(num * 2);
        q.pop();
    }
    return -1;
}

int main(){
    int N, K;
    while(cin >> N >> K){
        cout << level_search(N, K) << endl;
    }
    return 0;
}