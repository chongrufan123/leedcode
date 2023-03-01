#include <iostream>

using namespace std;

long long factorial(int n){
    if(n > 1)
        return n * factorial(n - 1);
    else
        return n;
}

int main(){
    int n;
    while(cin >> n){
        cout << factorial(n) << endl;
    }
    return 0;
}