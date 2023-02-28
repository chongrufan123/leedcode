// 今年暑假不AC
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp_second(pair<int, int> p1, pair<int, int> p2){
    return p1.second < p2.second;
}

bool cmp_first(pair<int, int> p1, pair<int, int> p2){
    return p1.first < p2.first;
}


int main(){
    int num;
    int count;
    vector<pair<int, int> > TVtime;
    vector<pair<int, int> >::iterator it;
    int first;
    pair<int, int> time_temp;
    while(cin >> num){
        count = 0;
        if(num == 0) break;
        for(int i = 0; i < num; ++i){
            cin >> time_temp.first >> time_temp.second;
            TVtime.push_back(time_temp);
        }
        while(!TVtime.empty()){
            it = min_element(TVtime.begin(), TVtime.end(), cmp_second);
            first = it.base()->second;
            TVtime.erase(it);
            sort(TVtime.begin(), TVtime.end(), cmp_first);
            while(TVtime.begin().base()->first < first && !TVtime.empty()){
                TVtime.erase(TVtime.begin());
            }
            count++;
        }
        cout << count << endl;
    }
    return 0;
}