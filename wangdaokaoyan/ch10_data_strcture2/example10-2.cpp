#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct Btree{
    char data;
    struct Btree* left;
    struct Btree* right;
    Btree(char c) : data(c), left(nullptr), right(nullptr) {}
}Btree;


Btree* creat_tree(vector<char> pre, vector<char> in) {
    if(pre.empty() || in.empty()) return nullptr;
    char val = pre[0];
    Btree* t = new Btree(val);
    pre.erase(pre.begin());
    auto it = find(in.begin(), in.end(), val);
    vector<char> left_in(in.begin(), it);
    vector<char> right_in(it + 1, in.end());
    int left_size = it - in.begin();
    vector<char> left_pre(pre.begin(), pre.begin() + left_size);
    vector<char> right_pre(pre.begin() + left_size, pre.end());
    t->left = creat_tree(left_pre, left_in);
    t->right = creat_tree(right_pre, right_in);
    return t;
}

void AfterOrder(Btree* t){
    if(t == nullptr) return;
    if(t->left) AfterOrder(t->left);
    if(t->right) AfterOrder(t->right);
    cout << t->data;
}

int main(){
    vector<char> pre, in;
    Btree* t = new Btree('0');
    string pres, ins;
    while(cin >> pres){
        cin >> ins;
        for(int i = 0; i < pres.size(); ++i) pre.push_back(pres[i]);
        for(int i = 0; i < ins.size(); ++i) in.push_back(ins[i]);
        t = creat_tree(pre, in);
        AfterOrder(t);
        cout << endl;
    }
    return 0;
}