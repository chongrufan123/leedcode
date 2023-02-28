#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, m, count;
    string str;
    vector<string> agent;
    vector<string> server;
    vector<string> temp;
    while(cin >> n){
        count = 0;
        for(int i = 0; i < n; ++i){
            cin >> str;
            agent.push_back(str);
        }
        cin >> m;
        for(int i = 0; i < m; ++i){
            cin >> str;
            server.push_back(str);
        }
        temp = agent;
        vector<string>::iterator it;
        if(agent.size() == 0 ||
            (agent.size() == 1 &&
            find(server.begin(), server.end(), agent.front()) != server.end())
            )
        {
            cout << "-1" << endl;
            continue;
        }
        for(int i = 0; i < server.size(); ++i){
            it = find(temp.begin(), temp.end(), server.at(i));
            if(it == temp.end()) continue;
            else{
                temp.erase(it);
                i --;
            }
            if(temp.size() == 0){
                count ++;
                temp = agent;
            }
        }
        cout << count << endl;
    }
    return 0;
}