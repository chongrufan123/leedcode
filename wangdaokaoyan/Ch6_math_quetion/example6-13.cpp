#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10000;
struct BigInteger{
    int length;
    int digit[MAXN];
    BigInteger();
    BigInteger(int x);
    BigInteger(string str);
    BigInteger operator+(BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& a);
    friend ostream& operator<<(ostream& out, const BigInteger& a);
};

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length] = x;
        length ++;
    }
    while( x != 0 ){
        digit[length] = x % 10;
        x /= 10;
        length ++;
    }
}
BigInteger::BigInteger(string str){
    memset(digit, 0, sizeof(digit));
    length = str.length();
    for(int i = 0; i < length; ++i){
        digit[i] = str[length - 1 - i] - '0';
    }
}

istream& operator>>(istream& in, BigInteger& a){
    string str;
    in >> str;
    a = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& a){
    for(int i = a.length - 1; i >= 0; --i){
        out << a.digit[i];
    }
    return out;
}

BigInteger BigInteger::operator+(BigInteger& b){
    int carry = 0;
    BigInteger result;
    for(int i = 0; i < length || i < b.length; ++i){
        result.length++;
        result.digit[i] = (digit[i] + b.digit[i] + carry) % 10;
        if(digit[i] + b.digit[i] + carry >= 10) carry = 1;
        else carry = 0;
    }
    for(int i = result.length; i < length; ++i){
        result.length++;
        result.digit[i] = (digit[i] + carry) % 10;
        if(digit[i] + carry >= 10) carry = 1;
        else carry = 0;
    }
    for(int i = result.length; i < b.length; ++i){
        result.length++;
        result.digit[i] = (b.digit[i] + carry) % 10;
        if(b.digit[i] + carry >= 10) carry = 1;
        else carry = 0;
    }
    return result;
}

int main(){
    BigInteger a, b;
    while (cin >> a >> b){
        cout << a + b << endl;
    }
    return 0;
}