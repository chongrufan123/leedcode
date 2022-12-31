// 今天是第几天
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

bool is_run(int year){  // 输入年份，输出是否是闰年
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main(){
    vector<int> day_per_month = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
    int year, month, day;
    while(cin >> year >> month >> day){
        if(is_run(year)){
            day_per_month[1] = 29;
        }else{
            day_per_month[1] = 28;
        }

        int sum_month = accumulate(day_per_month.begin(), day_per_month.begin() + month - 1, 0);
        cout << sum_month + day << endl;
    }
    return 0;
}