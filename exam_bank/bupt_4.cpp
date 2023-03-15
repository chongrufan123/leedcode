// 找最小数
// https://www.nowcoder.com/practice/ba91786c4759403992896d859e87a6cd
// Easy
#include <iostream>
#include <queue>

using namespace std;

struct my_data{
    int a;
    int b;
    my_data(int ma, int mb) : a(ma), b(mb) {}
    bool operator<(my_data const md)const{
        if(a == md.a) return b > md.b;
        else return a > md.a;
    }
};

int main(){
    int N;
    priority_queue<my_data> qmd;
    int x, y;
    while(cin >> N){
        for(int i = 0; i < N; ++i){
            cin >> x >> y;
            qmd.push(*(new my_data(x, y)));
        }
        cout << qmd.top().a << " " << qmd.top().b << endl;
        while(!qmd.empty()) qmd.pop();
    }
    return 0;
}