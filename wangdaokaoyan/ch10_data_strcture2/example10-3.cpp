#include <iostream>
#include <vector>
using namespace std;

struct Btree{
    unsigned data;
    Btree* left;
    Btree* right;
    Btree(unsigned i) : data(i), left(nullptr), right(nullptr) {}
};

void build_tree(Btree* root, vector<unsigned int> num){
    Btree* t;
    while(!num.empty()){
        int val = num.front();
        num.erase(num.begin());
        t = root;
        while(t != nullptr){
            if(val > t->data){
                if(t->right == nullptr){
                    cout << t->data << endl;
                    t->right = new Btree(val);
                    break;
                }
                else t = t->right;
            }
            if(val < t->data){
                if(t->left == nullptr){
                    cout << t->data << endl;
                    t->left = new Btree(val);
                    break;
                }
                else t = t->left;
            }
        }
    }
}

int main(){
    int N;
    int a;
    vector<unsigned int> num;
    while(cin >> N){
        for(int i = 0; i < N; ++i){
            cin >> a;
            num.push_back(a);
        }
        Btree* root = new Btree(num.front());
        cout << -1 << endl;
        num.erase(num.begin());
        build_tree(root, num);

    }
}