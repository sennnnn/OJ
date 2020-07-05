/*
    题目名字: 细菌的繁衍与扩散
    题目编号: 8215
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int m, n, i, j, k;
    int storage[11][11], temp[11][11];
    // 初始化
    scanf("%d %d", &m, &n);
    memset(storage, 0, sizeof(storage)); memset(temp, 0, sizeof(temp));
    storage[5][5] = m; temp[5][5] = m;
    for(k = 0; k < n; k++){
        for(i = 1; i <= 9; i++){
            for(j = 1; j <= 9; j++){
                temp[i-1][j-1]  += storage[i][j];
                temp[i-1][j]    += storage[i][j];
                temp[i-1][j+1]  += storage[i][j];
                temp[i][j+1]    += storage[i][j];
                temp[i+1][j+1]  += storage[i][j];
                temp[i+1][j]    += storage[i][j];
                temp[i+1][j-1]  += storage[i][j];
                temp[i][j-1]    += storage[i][j];
                temp[i][j]      += storage[i][j];
            }
        }
        for(i = 1; i <= 9; i++){
            for(j = 1; j <= 9; j++){
                storage[i][j] = temp[i][j];
            }
        }
    }

    for(i = 1; i <= 9; i++){
        for(j = 1; j <= 9; j++){
            printf("%d ", storage[i][j]);
        }
        printf("\n");
    }
    
}