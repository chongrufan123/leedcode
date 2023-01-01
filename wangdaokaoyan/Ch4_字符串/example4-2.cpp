// 密码翻译
#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        for(int i = 0; i < str.size(); ++i){
            if((str[i] >= 'a' && str[i] <= 'y') ||
                (str[i] >= 'A' && str[i] <= 'Y') ) str[i]++;
            else if(str[i] == 'Z') str[i] = 'A';
            else if(str[i] == 'z') str[i] = 'a';
            else continue;
        }
        cout << str << endl;
    }
    return 0;
}