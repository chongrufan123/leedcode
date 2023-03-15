// 打牌
// https://www.nowcoder.com/practice/82442ee76977479e8ab4b88dfadfca9f
// Hard
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool check_card(string a, string b){
    int num;
    vector<int> v;
    switch (b.length())
    {
    case 1:
        for(auto it = a.begin(); it != a.end(); ++it){
            if(*it.base() > b[0]) return true;
        }
        break;
    case 2:
        for(auto it = a.begin(); it+1 != a.end(); ++it){
            if(*it.base() == *((it+1).base()) && *it.base() > b[0]) return true;
        }
        break;
    case 3:
        for(auto it = a.begin(); it+2 != a.end(); ++it){
            num = *it.base();
            if(num == *((it+1).base()) && num == *((it+2).base()) && num > b[0]) return true;
        }
        break;
    case 4:
        for(auto it = a.begin(); it+3 != a.end(); ++it){
            num = *it.base();
            if(num == *((it+1).base())&&num == *((it+2).base())&&num == *((it+3).base()) && num > b[0]) return true;
        }
        break;
    case 5:
        for(int i = 0; i < a.length(); ++i){
            if(find(v.begin(), v.end(), a[i]) != v.end()) continue;
            v.push_back(a[i]);
        }
        for(auto it = v.begin(); it+4 != v.end(); ++it){
            num = *it.base();
            if(num == *((it+1).base())-1 &&num == *((it+2).base())-2 &&num == *((it+3).base())-3&& num == *((it+4).base())-4 
                && num > int(b[0])) return true;
        }
        break;
    default:
        break;
    }
    return false;
}

int main(){
    string a;
    string b;
    while(cin >> a){
        cin >> b;
        if(check_card(a, b)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
}