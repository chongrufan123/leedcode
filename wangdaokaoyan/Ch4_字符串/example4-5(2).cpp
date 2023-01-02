// 字母统计二解
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int number[26];
int main(){
    string str;
    while(cin >> str){
        memset(number, 0, sizeof(number));
        for (int  i = 0; i < str.size(); ++i){
            if ('A' <= str[i] && str[i] <='Z'){
                number[str[i] - 'A']++;
            }
        }
        for (int i = 0; i <26; ++i){
            cout << 'A' + i << ":" << number[i] << endl;
        }
    }
    return 0;
}