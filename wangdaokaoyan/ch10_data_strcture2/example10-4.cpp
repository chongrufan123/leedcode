#include <iostream>
#include <vector>

using namespace std;

struct Btree{
    int data;
    Btree* left;
    Btree* right;
    Btree(int a) : data(a), left(nullptr), right(nullptr) {}
};

void build_tree(Btree* root, vector<int>& num){
    Btree* t;
    int val;
    while(!num.empty()){
        t = root;
        val = num.front();
        num.erase(num.begin());
        while(true){
            if(val < t->data){
                if(t->left == nullptr){
                    t->left = new Btree(val);
                    break;
                }
                else
                    t = t->left;
            }
            else if(val > t->data){
                if(t->right == nullptr){
                    t->right = new Btree(val);
                    break;
                }
                else
                    t = t->right;
            }
            else break;
        }
    }
}

void PreOrder(Btree* root){
    if(root == nullptr) return;
    cout << root->data << " ";
    if(root->left != nullptr) PreOrder(root->left);
    if(root->right != nullptr) PreOrder(root->right);
}

void InOrder(Btree* root){
    if(root == nullptr) return;
    if(root->left != nullptr) InOrder(root->left);
    cout << root->data << " ";
    if(root->right != nullptr) InOrder(root->right);
}

void AfterOrder(Btree* root){
    if(root == nullptr) return;
    if(root->left != nullptr) AfterOrder(root->left);
    if(root->right != nullptr) AfterOrder(root->right);
    cout << root->data << " ";
}

int main(){
    int n, a;
    vector<int> num;
    Btree* root = new Btree(0);
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> a;
            num.push_back(a);
        }
        root->data = num.front();
        num.erase(num.begin());
        build_tree(root, num);
        PreOrder(root);
        cout << endl;
        InOrder(root);
        cout << endl;
        AfterOrder(root);
        cout << endl;
        root->left = nullptr;
        root->right = nullptr;
    }
    return 0;
}