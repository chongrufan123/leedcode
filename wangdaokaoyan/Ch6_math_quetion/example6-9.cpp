// 质因数的个数
#include <iostream>

using namespace std;

bool is_prime(int n){
    if(n == 1) return false;
    for(int i = 2; i * i < n; ++i){
        if(n % i == 0) return false;
    }
    return true;
}

int main(){
    int num;
    int count = 0;
    while(cin >> num){
        for(int i = 2; ; ++i){
            if((num % i == 0) && is_prime(i)){
                num /= i;
                count ++;
                i -= 1;
            }
            if(num == 1) break;
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}