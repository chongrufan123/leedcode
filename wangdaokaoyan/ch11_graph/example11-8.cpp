// Legal or Not
// 
// 
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct member{
    int mem;
    vector<int> master;
    vector<int> prentice;
    member(int m) : mem(m) {}
};

int main(){
    int n, m;
    vector<member> mem;
    int a, b;
    while(cin >> n >> m){
        if(n == 0 && m == 0) break;
        for(int i = 0; i < n; ++i){
            member* mm = new member(i);
            mem.push_back(*mm);
        }
        for(int i = 0; i < m; ++i){
            cin >> a >> b;
            mem[a].prentice.push_back(b);
            mem[b].master.push_back(a);
        }
        while(!mem.empty()){
            int size = mem.size();
            for(int i = 0; i < mem.size(); ++i){
                if(mem[i].master.empty()){ 
                    while(!mem[i].prentice.empty()){
                        for(int j = 0; j < mem.size(); ++j){
                            if(mem[j].mem == mem[i].prentice[0])
                                mem[j].master.pop_back();
                        }
                        mem[i].prentice.erase(mem[i].prentice.begin());
                    }
                    mem.erase(mem.begin() + i);
                }      
            }
            if(mem.size() == size){
                cout << "NO" << endl;
                break;
            }
        }
        if(mem.empty()) cout << "YES" << endl;
        else mem.erase(mem.begin(), mem.end());
    }
}

