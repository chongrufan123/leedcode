#include <iostream>
#include <cstring>

using namespace std;

const int MAXN = 10000;

struct BigInteger {
    int digit[MAXN];
    int length;
    BigInteger();
    BigInteger(int x);
    BigInteger(string str);
    BigInteger(const BigInteger& b);
    BigInteger operator=(int x);
    BigInteger operator=(string str);
    BigInteger operator=(const BigInteger& b);
    bool operator<=(const BigInteger& b);
    bool operator==(const BigInteger& b);
    BigInteger operator+(const BigInteger& b);
    BigInteger operator-(const BigInteger& b);
    BigInteger operator*(const BigInteger& b);
    BigInteger operator/(const BigInteger& b);
    BigInteger operator%(const BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& x);
    friend ostream& operator<<(ostream& out, const BigInteger& x);
};

istream& operator>>(istream& in, BigInteger& x){
    string str;
    in >> str;
    x = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& x){
    for (int i = x.length - 1; i >= 0; --i){
        out << x.digit[i];
    }
    return out;
}

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length++] = x;
    }
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

BigInteger::BigInteger(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < length; ++i){
        digit[i] = b.digit[i];
    }
}

BigInteger BigInteger::operator=(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length++] = x;
    }
    while(x != 0){
        digit[length++] = x % 10;
        x /= 10;
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < length; ++i){
        digit[i] = b.digit[i];
    }
    return *this;
}

bool BigInteger::operator<=(const BigInteger& b){
    if(length < b.length){
        return true;
    }else if(b.length < length){
        return false;
    }else{
        for(int i = length - 1; i >= 0; --i){
            if(digit[i] == b.digit[i]){
                continue;
            }else{
                return digit[i] < b.digit[i];
            }
        }
    }
    return true;
}

bool BigInteger::operator==(const BigInteger& b){
    if(length != b.length){
        return false;
    }else{
        for(int i = length - 1; i >= 0; --i){
            if(digit[i] != b.digit[i]){
                return false;
            }
        }
    }
    return true;
}

BigInteger BigInteger::operator*(const BigInteger& b){
    BigInteger answer;
    int carry = 0;
    for(int i = 0; i < length || i < b.length; ++i){
        int current = carry + digit[i] + b.digit[i];
        carry = current / 10;
        answer.digit[answer.length++] = current % 10;
    }
}