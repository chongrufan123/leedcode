// Number Sequence
// 使用KMP算法
#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

const int MAXM = 10000;
const int MAXN = 1000000;

int nextTable[MAXM];
int pattern[MAXM];
int text[MAXN];

void GetNextTable(int m){    // 创建next数组
    int j = 0;
    nextTable[j] = -1;
    int i = nextTable[j];
    while (j < m){
        if(i == -1 || pattern[j] == pattern[i]){
            i++;
            j++;
            nextTable[j] = i;
        }else
            i = nextTable[i];
    }
    return;
}

int KMP(int n, int m){
    GetNextTable(m);
    int i = 0;
    int j = 0;
    while( i < n && j < m){
        if( j == -1 || text[i] == pattern[j]){
            j++;
            i++;
        }else{
            j = nextTable[j];
        }
    }
    if(j == m){
        return i - j + 1;
    }else{
        return -1;
    }
}

int main(){
    int caseNumber;
    scanf("%d", &caseNumber);
    while(caseNumber--){
        int n, m;
        scanf("%d%d", &n, &m);
        for(int i = 0; i < n; ++i){
            scanf("%d", &text[i]);
        }
        for(int j = 0; j < m; ++j){
            scanf("%d", &pattern[j]);
        }
        printf("%d\n", KMP(n, m));
    }
    return 0;
}
