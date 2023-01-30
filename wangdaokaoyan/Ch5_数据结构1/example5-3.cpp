// 猫狗收容所
#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> my_animal;
    queue<int> car;
    queue<int> dog;
    queue<int> num;
    int n;
    int i, j;
    cin >> n;
    while( n-- ){
        cin >> i >> j;
        if(i == 1){
            my_animal.push(j);
            if(j > 0) dog.push(j);
            else if(j < 0) car.push(j);
        }
        if(i == 2){
            if(j == 0){
                if(!my_animal.empty()){
                    num.push(my_animal.front());
                    if(num.back() > 0) dog.pop();
                    else if(num.back() < 0) car.pop();
                    my_animal.pop();
                }
            }
            if(j == 1){
                if(!dog.empty()){
                    num.push(dog.front());
                    dog.pop();
                    my_animal.pop();
                }
            }
            if(j == -1){
                if(!car.empty()){
                    num.push(car.front());
                    car.pop();
                    my_animal.pop();
                }
            }
        }
    }
    while(!num.empty()){
        cout << num.front() << " ";
        num.pop();
    }
    return 0;
}