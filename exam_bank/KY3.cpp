// 约数的个数
// https://www.nowcoder.com/practice/04c8a5ea209d41798d23b59f053fa4d6
// Hard
#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1000000000;

int get_few(int x){
    if(x == 1) return 1;
    int count = 1;
    for(int i = 2; i < sqrt(x); ++i){
        if(x % i == 0) count++;
    }
    if(int(sqrt(x)) * int(sqrt(x)) == x) return count * 2 + 1;
    else return count * 2;
}

int main(){
    int N;
    vector<int> num;
    int n;
    while(cin >> N){
        for(int i = 0; i < N; ++i){
            cin >> n;
            num.push_back(n);
        }
        while(!num.empty()){
            cout << get_few(num.front()) << endl;
            num.erase(num.begin());
        }
    }
    return 0;
}