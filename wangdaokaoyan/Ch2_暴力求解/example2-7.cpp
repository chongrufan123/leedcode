// 打印日期
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool is_run(int year){  // 输入年份，输出是否是闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main(){
    vector<int> day_per_month = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int y, n;
    while(cin >> y >> n){
        if(is_run(y)){
            day_per_month[1] = 29;
        }else{
            if(n > 365){
                cout << "error!" << endl;
                continue;
            }
            else
                day_per_month[1] = 28;
        }
        int month = 1;
        int dd = n;
        while(dd > day_per_month[month - 1]){
            dd -= day_per_month[month - 1];
            month++;
        }
        printf("%04d-%02d-%02d\n", y, month, dd);
        // cout << y << "-" << month << "-" << dd << endl;
    }
    return 0;
}