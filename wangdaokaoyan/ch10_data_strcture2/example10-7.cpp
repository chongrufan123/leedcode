#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

int main(){
    int N;
    map<string, string> stu;
    cin >> N;
    getchar();
    string s;
    for(int i = 0; i < N; ++i){
        getline(cin, s);
        auto it = find(s.begin(), s.end(), ' ');
        string sf(s.begin(), it);
        string sl(it + 1, s.end());
        stu[sf] = sl;
    }
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> s;
        if(stu.find(s) == stu.end()) cout << "No Answer!" << endl;
        else cout << s << " " <<  stu[s] << endl;
    }
    return 0;
}