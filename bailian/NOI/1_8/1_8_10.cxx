/*
    题目名字: 矩阵转置
    题目编号: 8064
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    int storage[110][110];
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &storage[i][j]);
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", storage[j][i]);
        }
        printf("\n");
    }
}