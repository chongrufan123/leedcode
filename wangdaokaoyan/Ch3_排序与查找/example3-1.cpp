// 排序
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> lists;
    cin >> n;
    int a;
    while(cin >> a){
        lists.push_back(a);
        n--;
        if(n <= 0) break;
    }
    sort(lists.begin(), lists.end());

    for(int i = 0; i < lists.size(); i++){
        cout << lists[i] << " ";
    }

    return 0;
}