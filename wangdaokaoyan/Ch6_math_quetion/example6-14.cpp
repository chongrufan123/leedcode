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
    BigInteger operator=(const BigInteger& b);
    BigInteger operator=(string str);
    BigInteger operator=(int x);
    BigInteger operator*(int b);
    friend istream& operator>>(istream& in, BigInteger& b);
    friend ostream& operator<<(ostream& out, const BigInteger& b);
    
};

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    while(x != 0){
        digit[length++] = x % 10;
        x /= 10;
    }
}

BigInteger::BigInteger(string str){
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for(int i = 0; i < length; ++i){
        digit[i] = str[length - i - 1] - '0';
    }
}

BigInteger BigInteger::operator*(int b){
    int carry = 0;
    BigInteger result;
    for(int i = 0; i < length; i++){
        result.digit[i] = (digit[i] * b + carry) % 10;
        carry = (carry + digit[i] * b) / 10;
        result.length ++;
    }
    while(carry != 0){
        result.digit[result.length++] = carry % 10;
        carry /= 10;
    }
    return result;
}

istream& operator>>(istream& in, BigInteger b){
    string str;
    in >> str;
    b = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& b){
    for(int i = b.length - 1; i >= 0; --i){
        out << b.digit[i];
    }
    return out;
}

BigInteger BigInteger::operator=(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < length; ++i){
        digit[i] = b.digit[i];
    }
    return *this;
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length = str.size();
    for(int i = 0; i < length; ++i){
        digit[i] = str[length - i - 1] - '0';
    }
    return *this;
}

BigInteger BigInteger::operator=(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    while(x != 0){
        digit[length++] = x % 10;
        x /= 10;
    }
    return *this;
}

void factorial(int x, BigInteger& result){
    for(int i = 1; i <= x; ++i){
        result = result * i;
    }
}

int main(){
    int x;
    BigInteger result = 1;
    while(cin >> x){
        factorial(x, result);
        cout << result << endl;
        result = 1;
    }
    return 0;
}