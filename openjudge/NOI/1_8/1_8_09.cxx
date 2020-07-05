/*
    题目名字: 矩阵乘法
    题目编号: 7544
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m, k;
    int A[110][110], B[110][110], res[110][110];
    memset(A, 0, sizeof(A)); memset(B, 0, sizeof(B)); memset(res, 0, sizeof(res));
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &A[i][j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= k; j++){
            scanf("%d", &B[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            for(int l = 1; l <= m; l++){
                res[i][j] += A[i][l]*B[l][j];
            }
            printf("%d ", res[i][j]);
        }
        printf("\n");
    }
    return 0;
}