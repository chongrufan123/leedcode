// 矩阵幂
#include <iostream>

using namespace std;

typedef struct Matrix{
    int row, col;
    int num[10][10] = {0};
    Matrix(int r, int c) : row(r), col(c) {}
}Matrix;

Matrix mul_matrix(Matrix a, Matrix b){
    Matrix ans(a.row, b.col);
    for(int i = 0; i < ans.row; ++i){
        for(int j = 0; j < ans.col; ++j){
            for(int k = 0; k < a.col; ++k){
                ans.num[i][j] += (a.num[i][k] * b.num[k][j]);
            }
        }
    }
    return ans;
}

void input_matrix(Matrix * mat, Matrix * ans){
    for(int i = 0; i < mat->row; ++i){
        for(int j = 0; j < mat->col; ++j){
            cin >> mat->num[i][j];
            ans->num[i][j] = mat->num[i][j];
        }
    }
}

void print_matrix(Matrix ans){
    for(int i = 0; i < ans.row; ++i){
        cout << ans.num[i][0];
        for(int j = 1; j < ans.col; ++j){
            cout << " " << ans.num[i][j];
        }
        cout << endl;
    }
}

int main(){
    int n, k;
    while(cin >> n >> k){
        Matrix mat(n, n);
        Matrix ans(n, n);
        input_matrix(&mat, &ans);
        for(int i = 0; i < k - 1; ++i){
            ans = mul_matrix(ans, mat);
        }
        print_matrix(ans);
    }

    return 0;
}