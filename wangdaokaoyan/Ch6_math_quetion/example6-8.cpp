// 素数
#include <iostream>
#include <vector>

using namespace std;

bool is_prime(int n){
    if( n < 2 ) return false;
    for(int i = 2; i * i <= n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    vector<int> ans;
    while(cin >> n){
        for(int i = 10; i < n; ++i){
            if(i % 10 == 1 && is_prime(i)) ans.push_back(i);
        }
        if(ans.empty()) cout << -1 << endl;
        else{
            for(int x: ans){
                cout << x << " ";
            }
            cout << endl;
        }
        ans.erase(ans.begin(), ans.end());
    }

    return 0;
}