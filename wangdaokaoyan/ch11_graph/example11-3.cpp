// Is it a tree?
// http://t.cn/Ai07FyDO
// Medium

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Tree{
    int data;
    vector<Tree*> child;
    Tree* parent;
    Tree(int a) : data(a), parent(nullptr) {}
};

bool is_tree(vector<Tree*> t){
    if(t.empty()) return true;
    Tree* root = nullptr;
    for(auto it = t.begin(); it != t.end(); ++it){
        if(root == nullptr && (*it.base())->parent == nullptr){
            root = *it.base();
            t.erase(it);
        }
        if(root != nullptr && (*it.base())->parent == nullptr) {return false; }
    }
    if(root == nullptr){return false;}
    queue<Tree*> tq;
    tq.push(root);
    while(!tq.empty()){
        Tree* tt = tq.front();
        while(!(tt->child.empty())){
            tq.push(tt->child.front());
            auto it = find(t.begin(), t.end(), tt->child.front());
            tt->child.erase(tt->child.begin());
            if(it == t.end()) {return false;}
            else t.erase(it);
        }
        tq.pop();
    }
    if(!t.empty()) return false;
    return true;
}

int main(){
    vector<Tree*> t;
    vector<int> d;
    Tree* t1, *t2;
    int a, b;
    int num = 0;
    while(true){
        num++;
        t.erase(t.begin(), t.end());
        d.erase(d.begin(), d.end());
        while(cin >> a >> b){
            if((a == 0 && b == 0) || (a == -1 && b == -1)) break;
            if(find(d.begin(), d.end(), a) == d.end()){
                t1 = new Tree(a);
                d.push_back(a);
                t.push_back(t1);
            }
            else{
                auto it = t.begin();
                while(it != t.end()){
                    if((*it.base())->data == a){
                        t1 = *it.base();
                        break;
                    }
                    it ++;
                }
            }
            if(find(d.begin(), d.end(), b) == d.end()){
                t2 = new Tree(b);
                d.push_back(b);
                t.push_back(t2);
            }
            else{
                auto it = t.begin();
                while(it != t.end()){
                    if((*it.base())->data == b){
                        t2 = *it.base();
                        break;
                    }
                    it ++;
                }
            }
            t1->child.push_back(t2);
            t2->parent = t1;
        }
        if(a == 0 && b == 0){
            if(is_tree(t)) cout << "Case " << num << " is a tree." << endl;
            else cout << "Case " << num << " is not a tree." << endl;
            continue;
        }
        if(a == -1 && b == -1) break;
    }
}
