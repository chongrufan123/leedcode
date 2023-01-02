// 字母统计
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    string ABC = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int count;
    while(getline(cin, str)){
        for(int i = 0; i < ABC.size(); ++i){
            for(int j = 0; j < str.size(); ++j){
                if(str[j] == ABC[i]) count++;
            }
            cout << ABC[i] << ":" << count << endl;
            count = 0;
        }
    }
    return 0;
}