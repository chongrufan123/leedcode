// 统计字符
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    string str;
    string c;
    int count = 0;
    while(getline(cin, c)){
        if(c == "#") break;
        getline(cin, str);
        for(int i = 0; i < c.size(); ++i){
            for(int j = 0; j < str.size(); ++j){
                if(c[i] == str[j]) count++;
            }
            cout << c[i] << " " << count << endl;
            count = 0;
        }
    }
    return 0;
}