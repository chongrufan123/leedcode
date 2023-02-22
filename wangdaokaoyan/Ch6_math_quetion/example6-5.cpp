// 最大公约数
#include <iostream>

using namespace std;

int max(int a, int b){
    if(a >= b) return a;
    else return b;
}

int min( int a, int b ){
    if( a >= b ) return b;
    else return a;
}

void yueshu(int a, int b, int &answer){
    if( max(a, b) % min(a, b) == 0 ){
        answer = min(a, b);
        return;
    }
    yueshu(min(a, b), max(a, b) % min(a, b), answer);
}

int main(){
    int a, b;
    int r;
    int answer;
    while( cin >> a >> b ){
        yueshu(a, b, answer);
        cout << answer << endl;
    }

    return 0;
}