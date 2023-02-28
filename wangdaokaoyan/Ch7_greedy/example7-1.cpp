#include <iostream>

using namespace std;

int min_count(int feet){
    int count;
    count = feet / 4;
    feet = feet % 4;
    if(feet == 1 || feet == 3) return 0;
    else if(feet == 2) return count + 1;
    else return count;
}

int max_count(int feet){
    int count;
    count = feet / 2;
    feet = feet % 2;
    if(feet == 1) return 0;
    else return count;
}


int main(){
    int feet;
    int min, max;
    while(cin >> feet){
        min = min_count(feet);
        max = max_count(feet);
        cout << min << " " << max << endl;
    }
    return 0;
}