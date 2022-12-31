// 日期累加
#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> day_per_month = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 
void is_run(int year){  // 输入年份，输出是否是闰年
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)){
        day_per_month[1] = 29;
    }else{
        day_per_month[1] = 28;
    }
    return;
}
int main(){
    int m, year, month, day, lei;
    cin >> m;
    for(int i = 0; i < m; ++i){
        cin >> year >> month >> day >> lei;
        is_run(year);
        if(lei <= day_per_month[month - 1] - day){
            printf("%04d-%02d-%02d\n", year, month, day + lei);
            continue;
        }
        else {
            lei -= (day_per_month[month - 1] - day);
            month ++;
        }
        if(month > 12){
            year++;
            month = 1;
            is_run(year);
        }
        while(lei > day_per_month[month - 1]){
            lei -= day_per_month[month - 1];
            month ++;
            if(month > 12){
                year++;
                month = 1;
                is_run(year);
            }
        }
        printf("%04d-%02d-%02d\n", year, month, lei);      
    }
    return 0;
}