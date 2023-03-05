#include <iostream>

using namespace std;

string str;

typedef struct Btree{
    char data;
    struct Btree* left;
    struct Btree* right;
    Btree(char c) : data(c), left(nullptr), right(nullptr) {}
}Btree;

void visit(Btree* t){
    char c = str[0];
    if(c != '#'){
        t->data = c;
        t->left = new Btree('0');
        t->right = new Btree('0');
        str.erase(str.begin());
    }
    else{
        t -> left = nullptr;
        t -> right = nullptr;
        str.erase(str.begin());
    }
}

void preOrder(Btree* t){
    if(str.empty()) return;
    visit(t);
    if(t->left != nullptr) preOrder(t->left);
    if(t->right != nullptr) preOrder(t->right);
}

void midOrder(Btree* t){
    if(t->data == '0') return;
    midOrder(t->left);
    cout << t->data << " ";
    midOrder(t->right);
}

int main(){
    Btree* p = new Btree('0');
    while(cin >> str){
        preOrder(p);
        midOrder(p);
        cout << endl;
    }
    return 0;
}