#include <iostream>
using namespace std;
int n; // 物品数量
int a[21]; // 物品体积
int num = 0; // 方案数

// 深度优先搜索
void dfs(int i, int j) {
    if (i == n || j == 0) { // 所有物品都考虑过了或者剩余容量为0
        if (j == 0) num++; // 如果剩余容量为0，则方案数加一
        return;
    }
    dfs(i + 1, j); // 不选第i个物品
    dfs(i + 1, j - a[i]); // 选第i个物品
}

int main() {
    // cin >> n; // 输入物品数量
    n = 3;
    a[0] = 10;
    a[1] = 20;
    a[2] = 30;
    // for (int i = 0; i < n; i++) {
    //     cin >> a[i]; // 输入每个物品的体积
    // }
    dfs(0, 40); // 开始搜索
    cout << num << endl; // 输出方案数
}