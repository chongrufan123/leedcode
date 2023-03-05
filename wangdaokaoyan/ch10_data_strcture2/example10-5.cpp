#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <map>
using namespace std;

priority_queue<int> q;
map<int, string> m;

void pop_q(){
    if(q.empty()){
        cout << "empty" << endl;
        return;
    }
    cout << m[q.top()] << endl;
    q.pop();
    cout << "SIZE = " << q.size() << endl;
}

int main(){
    int n;
    vector<string> com;
    string str;
    while(cin >> n){
        getchar();
        for(int i = 0; i < n; ++i){
            getline(cin, str);
            com.push_back(str);
        }
        while(!com.empty()){
            if(com.front() == "Pop") pop_q();
            if(com.front().front() == 'I'){
                auto it = find(com.front().begin(), com.front().end(), ' ');
                string num(it + 1, com.front().end());
                it = find(num.begin(), num.end(), '+');
                string nr(num.begin(), it);
                string nv(it + 2, num.end());
                int real = 0;
                int vir = 0;
                while(true){
                    real += nr.front() - '0';
                    nr.erase(nr.begin());
                    if(!nr.empty()) real *= 10;
                    else break;
                }
                while(true){
                    vir += nv.front() - '0';
                    nv.erase(nv.begin());
                    if(!nv.empty()) vir *= 10;
                    else break;
                }
                int d = real * real + vir * vir;
                m[d] = num;
                q.push(d);
                cout << "SIZE = " << q.size() << endl;
            }
            com.erase(com.begin());
        }
        while(!q.empty()) q.pop();
        m.erase(m.begin(), m.end());
    }
}
/*
88
Insert 407+i235
Insert 242+i490
Pop
Insert 21+i886
Insert 485+i838
Insert 866+i293
Insert 728+i160
Insert 307+i786
Insert 176+i738
Pop
Pop
Insert 694+i261
Pop
Pop
Pop
Insert 124+i100
Pop
Insert 572+i98
Insert 421+i393
Pop
Insert 741+i146
Insert 358+i936
Insert 751+i662
Pop
Insert 28+i484
Insert 888+i410
Insert 531+i883
Insert 706+i913
Pop
Pop
Pop
Pop
Pop
Insert 59+i792
Pop
Pop
Pop
Pop
Insert 702+i537
Pop
Pop
Insert 143+i446
Insert 235+i710
Pop
Pop
Insert 800+i522
Insert 839+i675
Insert 946+i477
Insert 150+i923
Insert 505+i661
Pop
Pop
Pop
Pop
Pop
Insert 875+i25
Pop
Insert 967+i490
Pop
Insert 797+i231
Insert 28+i237
Pop
Pop
Insert 895+i200
Insert 713+i466
Insert 237+i344
Pop
Pop
Insert 938+i546
Pop
Insert 650+i247
Pop
Pop
Insert 689+i915
Insert 700+i672
Pop
Pop
Insert 383+i603
Pop
Pop
Pop
Insert 493+i392
Insert 848+i364
Pop
Insert 465+i304
Pop
Insert 897+i635
Insert 934+i123


SIZE = 1
SIZE = 2
242+i490
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
SIZE = 5
SIZE = 6
SIZE = 7
485+i838
SIZE = 6
866+i293
SIZE = 5
SIZE = 6
21+i886
SIZE = 5
307+i786
SIZE = 4
176+i738
SIZE = 3
SIZE = 4
728+i160
SIZE = 3
SIZE = 4
SIZE = 5
694+i261
SIZE = 4
SIZE = 5
SIZE = 6
SIZE = 7
358+i936
SIZE = 6
SIZE = 7
SIZE = 8
SIZE = 9
SIZE = 10
706+i913
SIZE = 9
531+i883
SIZE = 8
751+i662
SIZE = 7
888+i410
SIZE = 6
741+i146
SIZE = 5
SIZE = 6
59+i792
SIZE = 5
572+i98
SIZE = 4
421+i393
SIZE = 3
28+i484
SIZE = 2
SIZE = 3
702+i537
SIZE = 2
407+i235
SIZE = 1
SIZE = 2
SIZE = 3
235+i710
SIZE = 2
143+i446
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
SIZE = 5
SIZE = 6
839+i675
SIZE = 5
946+i477
SIZE = 4
800+i522
SIZE = 3
150+i923
SIZE = 2
505+i661
SIZE = 1
SIZE = 2
875+i25
SIZE = 1
SIZE = 2
967+i490
SIZE = 1
SIZE = 2
SIZE = 3
797+i231
SIZE = 2
28+i237
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
895+i200
SIZE = 3
713+i466
SIZE = 2
SIZE = 3
938+i546
SIZE = 2
SIZE = 3
650+i247
SIZE = 2
237+i344
SIZE = 1
SIZE = 2
SIZE = 3
689+i915
SIZE = 2
700+i672
SIZE = 1
SIZE = 2
383+i603
SIZE = 1
124+i100
SIZE = 0
empty
SIZE = 1
SIZE = 2
848+i364
SIZE = 1
SIZE = 2
493+i392
SIZE = 1
SIZE = 2
SIZE = 3


SIZE = 1
SIZE = 2
242+i490
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
SIZE = 5
SIZE = 6
SIZE = 7
485+i838
SIZE = 6
866+i293
SIZE = 5
SIZE = 6
307+i786
SIZE = 5
694+i261
SIZE = 4
176+i738
SIZE = 3
SIZE = 4
728+i160
SIZE = 3
SIZE = 4
SIZE = 5
421+i393
SIZE = 4
SIZE = 5
SIZE = 6
SIZE = 7
751+i662
SIZE = 6
SIZE = 7
SIZE = 8
SIZE = 9
SIZE = 10
706+i913
SIZE = 9
531+i883
SIZE = 8
358+i936
SIZE = 7
888+i410
SIZE = 6
741+i146
SIZE = 5
SIZE = 6
407+i235
SIZE = 5
124+i100
SIZE = 4
21+i886
SIZE = 3
59+i792
SIZE = 2
SIZE = 3
702+i537
SIZE = 2
572+i98
SIZE = 1
SIZE = 2
SIZE = 3
235+i710
SIZE = 2
143+i446
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
SIZE = 5
SIZE = 6
839+i675
SIZE = 5
946+i477
SIZE = 4
800+i522
SIZE = 3
505+i661
SIZE = 2
150+i923
SIZE = 1
SIZE = 2
875+i25
SIZE = 1
SIZE = 2
967+i490
SIZE = 1
SIZE = 2
SIZE = 3
797+i231
SIZE = 2
28+i484
SIZE = 1
SIZE = 2
SIZE = 3
SIZE = 4
713+i466
SIZE = 3
895+i200
SIZE = 2
SIZE = 3
938+i546
SIZE = 2
SIZE = 3
650+i247
SIZE = 2
237+i344
SIZE = 1
SIZE = 2
SIZE = 3
689+i915
SIZE = 2
700+i672
SIZE = 1
SIZE = 2
383+i603
SIZE = 1
28+i237
SIZE = 0
empty
SIZE = 1
SIZE = 2
848+i364
SIZE = 1
SIZE = 2
493+i392
SIZE = 1
SIZE = 2
SIZE = 3

*/