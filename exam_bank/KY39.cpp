// 大整数的因子
// https://www.nowcoder.com/practice/3d6cee12fbf54ea99bb165cbaba5823d
// Medium
#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 31;

class BigIntger{
public:
    int length;
    int data[MAXN];
    BigIntger(string d);
    BigIntger();
    int operator%(int const k);
};

BigIntger::BigIntger(string d){
    memset(data, 0, sizeof(data));
    length = d.length();
    for(int i = d.length() - 1; i >= 0; --i){
        data[d.length() - i - 1] = d[i] - '0';
    }
}

BigIntger::BigIntger(){
    memset(data, 0, sizeof(data));
    length = 0;
}

int BigIntger::operator%(int const k){
    int carry = 0;
    for(int i = length - 1; i >= 0; --i){
        carry = (data[i] + carry) % k;
        carry *= 10;
    }
    carry /= 10;
    return carry;
}

int main(){
    string mdata;
    bool space = false;
    while(cin >> mdata){
        if(mdata == "-1") break;
        BigIntger* bi = new BigIntger(mdata);
        for(int k = 2 ; k < 10; ++k){
            if(*bi % k == 0){
                if(space) cout << " " << k;
                else {
                    cout << k;
                    space = true;
                }
            }
        }
        if(!space) cout << "none";
        cout << endl;
        space = false;
    }
    // string mdata;
    // cin >> mdata;
    // BigIntger* bi = new BigIntger(mdata);
    // cout << *bi % 2 << endl;
}