#include <iostream>
#include <queue>

using namespace std;

int aw = 0;

struct Huffman{
    int weight;
    Huffman* left;
    Huffman* right;
    Huffman(int w) : weight(w), left(nullptr), right(nullptr) {}
};

class Myint{
    public:
    int data;
    Huffman* huf;
    bool operator<(const Myint& m) const{
        return data > m.data;
    }

    friend istream& operator>>(istream& in, Myint& m){
        in >> m.data;
        return in;
    }
    Myint(int i) : data(i), huf(nullptr) {}
};

Huffman* build_tree(priority_queue<Myint> q){
    while(q.size() != 1){
        Huffman* t1, *t2, *t3;
        if(q.top().huf == nullptr)
            t1 = new Huffman(q.top().data);
        else
            t1 = q.top().huf;
        q.pop();
        if(q.top().huf == nullptr)
            t2 = new Huffman(q.top().data);
        else
            t2 = q.top().huf;
        q.pop();
        t3 = new Huffman(t1->weight + t2->weight);
        t3->left = t1;
        t3->right = t2;
        Myint* i = new Myint(t1->weight + t2->weight);
        i->huf = t3;
        q.push(*i);
    }
    return q.top().huf;
}

void PreOrder(Huffman* root, int level){
    if(root == nullptr) return;
    if(root->left == nullptr && root->right == nullptr)
        aw += level * root->weight;
    if(root->left != nullptr) PreOrder(root->left, level + 1);
    if(root->right != nullptr) PreOrder(root->right, level + 1);
}

int main(){
    int n;
    priority_queue<Myint> mweight;
    Myint w(0);
    Huffman* root = new Huffman(0);
    while(cin >> n){
        for(int i = 0; i < n; ++i){
            cin >> w;
            mweight.push(w);
        }
        root = build_tree(mweight);
        PreOrder(root, 0);
        cout << aw << endl;
        aw = 0;
    }
}