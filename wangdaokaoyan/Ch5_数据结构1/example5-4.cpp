// Zero-complexity Transposition
#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    stack<int> seq;
    int num;
    cin >> n;
    while(n--){
        cin >> num;
        seq.push(num);
    }
    while(!seq.empty()){
        cout << seq.top() << " ";
        seq.pop();
    }
    return 0;
}