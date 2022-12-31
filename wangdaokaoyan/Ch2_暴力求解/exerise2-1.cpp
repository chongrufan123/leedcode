// 与7无关的数
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int calcu = 0;
    for(int ix = 1; ix <= n; ++ix){
        if(ix % 10 != 7 && ix % 7 != 0)
            calcu += ix * ix;
    }
    cout << calcu << endl;

    return 0;
}