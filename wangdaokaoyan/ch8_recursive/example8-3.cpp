#include <iostream>
#include <string>
using namespace std;
void fullRank(string pre, string str){
    if(str.size() == 1){//递归终止条件，只剩一个字母的全排列
        cout << pre + str << endl;
        return ;
    }
    //继续递归
    string nextpre = "";
    string nextstr = "";
    for(int i = 0; i < str.size(); i++){
        nextpre = pre + str[i];
        nextstr = str;
        nextstr.erase(i, 1);//剔除该字母
        fullRank(nextpre, nextstr);
    }
}
int main(){
    string str = "";
    cin >> str;
    /*
    递归：
    abc的全排列 = a开头bc的全排列 + b开头ac的全排列 + c开头ab的全排列
    其中，bc的全排列 = b开头c的全排列 + c开头b的全排列
    以此类推......
    */
    fullRank("", str);
    return 0;
}

