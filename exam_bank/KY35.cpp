// 最简真分数
// https://www.nowcoder.com/practice/1f1db273eeb745c6ac83e91ff14d2ec9
// Medium

#include <iostream>
#include <vector>

using namespace std;

bool gongyueshu(int a, int b){
    int r;
    int x = max(a, b);
    int y = min(a, b);
    while(true){
        r = x % y;
        if(r == 0){
            if(y == 1) return true;
            else return false;
        }
        x = y;
        y = r;
    }
    return 0;
}

int main(){
    int n;
    vector<int> vi;
    int x;
    while(cin >> n){
        if(n == 0) return 0;
        int num = 0;
        for(int i = 0; i < n; ++i){
            cin >> x;
            vi.push_back(x);
        }
        for(int i = 0; i < n - 1; ++i){
            for(int j = i+1; j < n; ++j){
                if(gongyueshu(vi[i], vi[j])){
                    num++;
                }
            }
        }
        cout << num << endl;
        vi.erase(vi.begin(), vi.end());
    }
}