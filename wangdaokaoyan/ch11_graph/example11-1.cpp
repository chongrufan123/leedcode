// 畅通工程
// http://t.cn/Ai0vBHj9
// Hard


#include<iostream>      
#include<cstdio>         
#include<algorithm> 

using namespace std;    //命名空间，定义区域

const int MAXN = 105;    //定义一个最大值

struct node 
{
    int a, b;      //起点和终点
    int len;      //边长
    bool operator<(node x)    //排序运算符的重载
    { 
        return len < x.len;   
    }
}road[MAXN];     //结构体数组

//并查集操作：
int tab[MAXN];       //存并查集
int father(int x)   //找父亲
{ 
    return (x == tab[x]) ? x : father(tab[x]);  
}
void Union(int a, int b)   //合并两个节点（的树）
{ 
    tab[father(b)] = father(a);  
}

bool CheckLink(int m) //判断图是否联通科分为多连通图
{
    int f = father(1);
    for (int i = 2; i <= m; i++) {
        if (f != father(i)) return false;
    }
    return true;
}

int main() 
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) //读入a,b,n,m四个参数对应边起点、便终点、总顶点数、总边数，
    {
        if (!n) break;
        //初始化并查集表
        for (int i = 1; i <= m; i++)
            tab[i] = i;

        //接下来输入n个具体数据，每个数据代表一条从a到b长度为len的边
        for (int i = 1; i <= n; i++) {
            scanf("%d%d%d", &road[i].a, &road[i].b, &road[i].len);
        }

        sort(road + 1, road + 1 + n);//kruskal核心：给输入的n个道路进行从小到大排序 

        int ans = 0;//预设一个变量(表示要输出正确的答案)

        for (int i = 1; i <= n; i++)//开始将排好序3000条路交叉加入，并查集，直至所有的终点都在新加入的这些边所构成的森林中
        {
            int a = road[i].a, b = road[i].b;//取出数组中的a,b
            if (father(a) == father(b)) continue; 
            Union(a, b);
            ans += road[i].len;
        }

        if (CheckLink(m)) printf("%d\n", ans);//万水千山总是情，成功输出答案qaq
        else printf("?\n"); ///无解输出?
    }
    return 0;   //结束整个程序
}
