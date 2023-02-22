// 计算两个矩阵的乘积
#include <iostream>

using namespace std;

int main(){
    int a[2][3], b[3][2];
    int ans[2][2] = {0};
    cin >> a[0][0] >> a[0][1] >> a[0][2];
    cin >> a[1][0] >> a[1][1] >> a[1][2];
    cin >> b[0][0] >> b[0][1];
    cin >> b[1][0] >> b[1][1];
    cin >> b[2][0] >> b[2][1];
    for(int i = 0; i < 2; ++i){
        for(int j = 0; j < 2; ++j){
            ans[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j] + a[i][2] * b[2][j];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}