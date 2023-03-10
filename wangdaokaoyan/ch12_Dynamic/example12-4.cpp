// 拦截导弹
// http://t.cn/AiYCeV3m
// Medium
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int MAXK = 25;

struct missile{
    int so;
    int height;
    bool operator<(const missile& m) const{
        return height < m.height;
    }
};

int main(){
    int k;
    int a[MAXK];
    priority_queue<missile> dy;
    vector<missile> temp;
    missile mis;
    while(cin >> k){
        memset(a, 0, sizeof(a));
        for(int i = 0; i < k; ++i){
            cin >> a[i];
        }
        mis.so = 0;
        mis.height = 1;
        dy.push(mis);
        for(int i = 1; i < k; ++i){
            while(!dy.empty()){
                if(a[i] <= a[dy.top().so]){
                    mis.so = i;
                    mis.height = dy.top().height + 1;
                    dy.push(mis);
                    break;
                }
                else{
                    temp.push_back(dy.top());
                    dy.pop();
                }
            }
            if(dy.empty()){
                mis.so = i;
                mis.height = 1;
                dy.push(mis);
            }
            while(!temp.empty()){
                dy.push(temp.front());
                temp.erase(temp.begin());
            }
        }
        // for(int i = 0; i < k; ++ i){
        //     cout << "第" << i + 1 << "个数字是： " << dy[i] << endl;
        // }
        cout << dy.top().height << endl;
        while(!dy.empty()) dy.pop();
    }
}
