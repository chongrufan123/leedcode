// 查找
// https://www.nowcoder.com/practice/a988eda518f242c29009f8620f654ede
// Hard
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string str;
    int n;
    string com;
    char temp;
    while(cin >> str){
        cin >> n;
        for(int i = 0; i < n; ++i){
            cin >> com;
            if(com[0] == '0'){
                int len = com[2] - '0' - 1;
                for(int j = 0; j <= len / 2; ++j){
                    temp = str[j + com[1] - '0'];
                    str[j + com[1] - '0'] = str[len + com[1] - '0' - j];
                    str[len + com[1] - '0' - j] = temp;
                }
            }
            if(com[0] == '1'){
                string str1(str.begin(), str.begin() + com[1] - '0');
                string str2(str.begin() + com[1] - '0' + com[2] - '0', str.end());
                com.erase(com.begin(), com.begin() + 3);
                str = str1 + com + str2;
            }
            cout << str << endl;
        }
    }
}


