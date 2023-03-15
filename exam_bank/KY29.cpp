// 谁是你的潜在朋友
// https://www.nowcoder.com/practice/0177394fb25b42b48657bc2b1c6f9fcc
// Medium
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXM = 201;

int main(){
    int N, M;
    vector<int> v;
    int n;
    int num[MAXM];
    while(cin >> N >> M){
        memset(num, 0, sizeof(num));
        for(int i = 0; i < N; ++i){
            cin >> n;
            v.push_back(n);
            num[n]++;
        }
        while(!v.empty()){
            n = v.front();
            if(num[n] == 1) cout << "BeiJu" << endl;
            else cout << num[n] - 1 << endl;
            v.erase(v.begin());
        }
    }
    return 0;
}