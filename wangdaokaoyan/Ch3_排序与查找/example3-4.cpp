// 找x
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a;
    int x;
    cin >> n;
    vector<int> num;
    for(int i = 0; i < n; ++i){
        cin >> a;
        num.push_back(a);
    }
    cin >> x;
    int count = find(num.begin(), num.end(), x) - num.begin();
    if(count >= n) cout << -1;
    else cout << count;
    return 0;
}