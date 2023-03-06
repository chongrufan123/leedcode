#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main(){
    map<string, string> magic, n_magic;
    string s;
    int n;
    while(getline(cin, s)){
        if(s == "@END@") break;
        auto it = find(s.begin() , s.end(), ']');
        string sf(s.begin(), it + 1);
        string sl(it + 2, s.end());
        magic[sf] = sl;
        n_magic[sl] = sf;
    }
    cin >> n;
    getchar();
    for(int i = 0; i < n; ++i){
        getline(cin, s);
        if(s[0] == '['){
            if(magic.find(s) == magic.end()) cout << "what?" << endl;
            else{
                cout << magic[s] << endl;
            }
        }
        else{
            if(n_magic.find(s) == n_magic.end()) cout << "what?" << endl;
            else{
                string st(n_magic[s].begin() + 1, n_magic[s].end() - 1);
                cout << st << endl;
            }
        }
    }
    return 0;
}