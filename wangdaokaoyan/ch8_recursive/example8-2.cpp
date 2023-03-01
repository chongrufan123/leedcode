// 汉诺塔
#include <iostream>

using namespace std;

long long hanoi(int n){
    if(n == 1) return 2;
    return (3 * hanoi(n - 1) + 2);
}

int main(){
    int n;
    while( cin >> n ){
        cout << hanoi(n) << endl;
    }
    return 0;
}