/*
    题目名字: 矩阵归零消减序列和
    题目编号: 6245
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int col_min_get(int (*s)[110], int index, int len){
    int min = 200000000;
    for(int i = 1; i <= len; i++){
        if(s[i][index] < min) min = s[i][index];
    }
    return min;
}

int row_min_get(int (*s)[110], int index, int len){
    int min = 200000000;
    for(int i = 1; i <= len; i++){
        if(s[index][i] < min) min = s[index][i];
    }
    return min;
}

int main(){
    int col_min, row_min;
    int n;
    int s[110][110];
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &s[i][j]);
        }
    }
    printf("%d\n", s[2][2]);
    for(int c = n; c > 1; c--){
        for(int i = 1; i <= c; i++){
            row_min = row_min_get(s, i, c);
            for(int j = 1; j <= c; j++){
                s[i][j] -= row_min;
            }
        }
        for(int j = 1; j <= c; j++){
            col_min = col_min_get(s, j, c);
            for(int i = 1; i <= c; i++){
                s[i][j] -= col_min;
            }
        }
        for(int i = 2; i <= c-1; i++){
            for(int j = 1; j <= c; j++){
                s[i][j] = s[i+1][j];
            }
        }
        for(int j = 2; j <= c-1; j++){
            for(int i = 1; i <= c; i++){
                s[i][j] = s[i][j+1];
            }
        }
        printf("%d\n", s[2][2]);
    }
}