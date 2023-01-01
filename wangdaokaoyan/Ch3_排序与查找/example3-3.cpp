// 成绩排序
#include <iostream>
#include <algorithm>

using namespace std;

typedef struct Stu
{
    string name;
    int score;
}Stu;

bool Compare_0(Stu x, Stu y ){
    return x.score >= y.score;
}

bool Compare_1(Stu x, Stu y){
    return y.score >= x.score;
}

int main(){
    int num;
    bool s;
    while(cin >> num){
        Stu *stu = new Stu[num];
        cin >> s;
        for(int i = 0; i < num; ++i){
            cin >> stu[i].name >> stu[i].score;
        }
        if(s) stable_sort(stu, stu + num, Compare_1);
        else stable_sort(stu, stu + num, Compare_0);

        for(int i = 0; i < num; ++i){
            cout << stu[i].name << " " << stu[i].score << endl;
        }
        delete [] stu;
    }
    return 0;
}
