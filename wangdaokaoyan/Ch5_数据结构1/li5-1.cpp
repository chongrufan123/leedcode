// vector练习

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

vector<int> myVector;

int main(){
    for(int i = 0; i < 5; ++i){
        myVector.push_back(i);
    }
    myVector.insert(myVector.begin(), 3, 15);
    myVector.pop_back();
    for(int i = 0; i < myVector.size(); ++i){
        cout << myVector[i] << " ";
    }
    cout << endl;
    cout << "the 5th element of myVector is " << myVector[4] << endl;
    cout << "the size of my Vector is " << myVector.size() << endl;
    myVector.erase(myVector.begin() + 5, myVector.end());
    vector<int>::iterator it;
    for(it = myVector.begin(); it != myVector.end(); it++)
        cout << *it << " ";
    cout << endl;
    myVector.clear();
    return 0;
}