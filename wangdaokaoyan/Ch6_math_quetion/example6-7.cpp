// 素数判定
#include <iostream>
#include <cmath>

using namespace std;

bool sushu(int num){
    if(num == 1) return false;
    int temp = 2;
    while(temp <= sqrt(num)){
        if(num % temp == 0) return false;
        temp ++;
    }
    return true;
}

int main(){
    int num;
    while(cin >> num){
        if(sushu(num)) cout << "yes" << endl;
        else cout << "no" << endl;
    }

    return 0;
}