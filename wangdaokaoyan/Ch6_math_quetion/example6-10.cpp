// 人见人爱的A^B
#include <iostream>

using namespace std;

void D_to_B(int b, int t[]){
    int count = 32768;
    for(int i = 15; i >= 0; --i){
        if(b == 0){
            t[i] = 0;
            continue;
        }
        if(b >= count){
            t[i] = 1;
            b -= count;
        }
        else t[i] = 0;
        count /= 2;
    }
}

int main(){
    int a, b;
    int count;
    int ans;
    int t[16] = {0};
    while(cin >> a >> b){
        if(a == 0 && b == 0) break;
        D_to_B(b, t);
        count = a % 1000;
        ans = 1;
        for(int i = 0; i < 16; ++i){
            if(t[i] == 1){
                ans = (ans * count) % 1000;
            }
            count = (count * count) % 1000;
        }
        cout << ans << endl;
    }

    return 0;
}