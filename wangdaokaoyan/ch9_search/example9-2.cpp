#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100;

typedef struct BigIntger{
    int length;
    int data[MAX];
    BigIntger();
    BigIntger(int i);
    BigIntger operator*(int n);
    BigIntger operator+(int n);
    friend ostream& operator<<(ostream& out, BigIntger& b);
    bool decetive();
}BigIntger;

BigIntger::BigIntger(){
    memset(data, 0, MAX);
    length = 0;
}

BigIntger::BigIntger(int i){
    memset(data, 0, MAX);
    length = 0;
    while(i != 0){
        data[length++] = i % 10;
        i /= 10;
    }
}

BigIntger BigIntger::operator+(int n){
    int carry = 0;
    BigIntger result;
    for(int i = 0; true; ++i){
        result.data[i] = (data[i] + (n % 10) + carry) % 10;
        carry = (data[i] + (n % 10) + carry) / 10;
        n /= 10;
        result.length ++;
        if(n == 0 && carry == 0 && result.length >= length) break;
    }
    return result;
}

BigIntger BigIntger::operator*(int n){
    int carry = 0;
    BigIntger result;
    for(int i = 0; i < length; ++i){
        result.data[i] = (data[i] * n + carry) % 10;
        carry = (data[i] * n + carry) / 10;
        result.length ++;
    }
    while(carry != 0){
        result.data[result.length++] = carry % 10;
        carry /= 10;
    }
    return result;
}

ostream& operator<<(ostream& out, BigIntger& b){
    for(int i = b.length - 1; i >= 0; -- i){
        out << b.data[i];
    }
    return out;
}

bool BigIntger::decetive(){
    for(int i = 0; i < length; ++i){
        if(data[i] != 1 && data[i] != 0) return false;
    }
    return true;
}

int main(){
    int n;
    BigIntger b = 8;
    BigIntger i = 1;
    while(cin >> n){
        if(n == 0) break;
        while(true){
            // b = b + n;
            b = i * n;
            i = i + 1;
            if(b.decetive()){
                cout << b << endl;
                break;
            }
        }
        i = 1;
    }

    return 0;
}