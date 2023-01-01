// 成绩排序
#include <iostream>
#include <algorithm>
using namespace std;

typedef struct Student{
    int num;
    int score;
}Student;

bool sort_by_score(Student stu1, Student stu2){
    if(stu1.score == stu2.score){
        return stu1.num < stu2.num;
    }else
        return stu1.score < stu2.score;
}

int main(){
    int N;
    int p, q;
    cin >> N;
    Student stu[N];
    for(int i = 0; i < N; ++i){
        cin >> p >> q;
        stu[i].num = p;
        stu[i].score = q;
    }
    sort(stu, stu + N, sort_by_score);
    for(int i = 0; i < N; ++i)
        cout << stu[i].num << " " << stu[i].score << endl;
    return 0;  
}