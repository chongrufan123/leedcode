// 简单密码
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    bool con = 0;
    while(getline(cin, str)){
        if(str == "START") {con = 1; continue;}
        else if(str == "END") con = 0;
        if(!con) continue;
        for(int i = 0; i < str.size(); ++i){
            if(str[i] >= 'A' && str[i] <= 'E') str[i]+=21;
            else if(str[i] >= 'F' && str[i] <= 'Z') str[i]-=5;
        }
        cout << str << endl;
    }
    return 0;
}