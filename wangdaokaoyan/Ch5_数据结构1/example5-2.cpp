// 约瑟夫问题 No.2
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int i;
    int n, p, m;
    queue<int> my_queue;
    vector<int> my_vector;
    vector<int>::iterator it;
    vector<int>::iterator it_temp;
    while(true){
        cin >> n >> p >> m;
        if( n == 0 && p == 0 && m == 0 ) break;
        for(i = 1; i <= n; ++i ){
            my_vector.push_back(i);
        }
        // for(it = my_vector.begin(); it != my_vector.end(); it++)
        //     cout << *it << " ";
        // cout << endl;
        it_temp = my_vector.begin() + p - 1;
        while(!my_vector.empty()){
            i = 0;
            it = it_temp;
            while(i < m){
                if(it == my_vector.end()) it = my_vector.begin();
                else it++;
                i++;
            }
            if(*it == *my_vector.end()) {it_temp = my_vector.begin();}
            else it_temp = it + 1;
            my_queue.push(*it);
            my_vector.erase(it);
        }
        cout << my_queue.size() << endl;
        for( i = 0; i < n - 1; ++i){
            cout << my_queue.front() << ",";
            my_queue.pop();
        }
        cout << my_queue.front() << endl;
        my_queue.pop();
    }
    return 0;
}