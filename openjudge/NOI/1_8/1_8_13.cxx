/*
    题目名字: 图像模糊处理
    题目编号: 8167
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int main(){
    int n, m, i, j;
    int storage[110][110], temp[110][110];
    double res;
    scanf("%d %d", &n, &m);
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            scanf("%d", &storage[i][j]);
            temp[i][j] = storage[i][j];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            if(i == 0 || i == n-1 || j == 0 || j == m-1) continue;
            res = (temp[i][j] + temp[i-1][j] + temp[i+1][j] + temp[i][j-1] + temp[i][j+1])/5.0;
            storage[i][j] = (int)floor(res+0.5);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < m; j++){
            printf("%d ", storage[i][j]);
        }
        printf("\n");
    }
}