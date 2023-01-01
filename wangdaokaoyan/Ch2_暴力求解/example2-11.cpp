// xxx定律
#include <iostream>
using namespace std;

int main(){
    int n;
    int count = 0;
    while(cin >> n){
        while( n > 1){
            if( n % 2 == 0) n/=2;
            else n = (3 * n + 1)/2;
            count ++;
        }
        cout << count << endl;
        count = 0;
    }
    return 0;
}