// 日志排序
// https://www.nowcoder.com/practice/0f64518fea254c0187ccf0ea05019672
// Medium
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

struct mlog{
    string str;
    float mtime;
    int stime;
    int ymd;
    mlog(string s) : str(s){
        mtime = 0;
        stime = 0;
        ymd = 0;
        float mtime_x = 0;
        int stime_h, stime_m, stime_s, stime_ms;
        auto it = find(s.begin(), s.end(), '(');
        it--;
        while(*it.base() != '.'){
            mtime_x = mtime_x * 0.1 + (*it.base() - '0') * 0.1;
            it--;
        }
        while(*((it - 1).base()) != ' '){
            it--;
        }
        while(*it.base() != '.'){
            mtime = mtime * 10 + (*it.base() - '0');
            it++;
        }
        mtime = mtime + mtime_x;
        while(*it.base() != ' ') it--;
        while(*it.base() == ' ') it--;
        while(*it.base() != ' ') it--;
        it++;
        while(*it.base() != ':'){
            stime_h = stime_h * 10 + (*it.base() - '0');
            it++;
        }
        it++;
        while(*it.base() != ':'){
            stime_m = stime_m * 10 + (*it.base() - '0');
            it++;
        }
        it++;
        while(*it.base() != ','){
            stime_s = stime_s * 10 + (*it.base() - '0');
            it++;
        }
        it++;
        while(*it.base() != ' '){
            stime_ms = stime_ms * 10 + (*it.base() - '0');
            it++;
        }
        stime = stime_h*24*60*1000 + stime_m*60*1000 + stime_s*1000 + stime_ms;
        it--;
        while(*it.base() != ' ') it--;
        while(*it.base() == ' ') it--;
        while(*it.base() != ' ') it--;
        it++;
        while(*it.base() != '-'){
            ymd = ymd * 10 + (*it.base() - '0');
            it++;
        }
        it++;
        while(*it.base() != '-'){
            ymd = ymd * 10 + (*it.base() - '0');
            it++;
        }
        it++;
        while(*it.base() != ' '){
            ymd = ymd * 10 + (*it.base() - '0');
            it++;
        }
        cout << stime << endl;
    }
    bool operator<(mlog const &m) const{
        if(mtime != m.mtime) return mtime > m.mtime;
        if(ymd != m.ymd) return ymd > m.ymd;
        if(stime != m.stime) return stime > m.stime;
        return true;
    }
};

int main(){
    priority_queue<mlog> lo;
    string st;
    while(true){
        getline(cin, st);
        if(st == "") break;
        lo.push(mlog(st));
    }
    while(!lo.empty()){
        cout << lo.top().str << endl;
        lo.pop();
    }
    return 0;
}
