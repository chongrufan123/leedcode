// 完数和盈数
#include <iostream>
#include <vector>

using namespace std;

void getyin(int i, vector<int> &myVector){
    for(int j = 1; j < i; ++j){
        if(i % j == 0) myVector.push_back(j);
    }
    return;
}

int main(){
    vector<int> myVector;
    vector<int> wan_number;
    vector<int> yin_number;
    vector<int>::iterator it;
    int sum = 0;
    for(int i = 2; i <= 60; ++i){
        getyin(i, myVector);
        // for(vector<int>::iterator it = myVector.begin(); it != myVector.end(); it++){
        //     cout << *it << " ";
        // }
        for(it = myVector.begin(); it != myVector.end(); it++){
            sum += *it;
        }
        if( i == sum ) wan_number.push_back(i);
        else if( i < sum ) yin_number.push_back(i);
        sum = 0;
        myVector.erase(myVector.begin(), myVector.end());
    }
    cout << "E: ";
    for(it = wan_number.begin(); it != wan_number.end(); it++){      
        cout << *it << " ";
    }
    cout << endl;
    cout << "G: ";
    for( it = yin_number.begin(); it != yin_number.end(); it++){
        cout << *it << " ";
    }
    
    return 0;
}