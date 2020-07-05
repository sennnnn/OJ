/*
    题目名字: 矩阵剪刀石头布
    题目编号: 1341
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int r, c, n;
    int i, j, k;
    char storage[110][110], temp[110][110];
    scanf("%d %d %d", &r, &c ,&n);
    memset(storage, 0, sizeof(storage)); memset(temp, 0, sizeof(temp));
    for(i = 1; i <= r; i++){
        scanf("%s", storage[i]+1);
        strcpy(temp[i]+1, storage[i]+1);
    }
    for(k = 0; k < n; k++){
        for(i = 1; i <= r; i++){
            for(j = 1; j <= c; j++){
                if(storage[i][j] == 'R'){
                    if(storage[i-1][j] == 'S') temp[i-1][j] = 'R';
                    if(storage[i+1][j] == 'S') temp[i+1][j] = 'R';
                    if(storage[i][j-1] == 'S') temp[i][j-1] = 'R';
                    if(storage[i][j+1] == 'S') temp[i][j+1] = 'R';
                }
                if(storage[i][j] == 'S'){
                    if(storage[i-1][j] == 'P') temp[i-1][j] = 'S';
                    if(storage[i+1][j] == 'P') temp[i+1][j] = 'S';
                    if(storage[i][j-1] == 'P') temp[i][j-1] = 'S';
                    if(storage[i][j+1] == 'P') temp[i][j+1] = 'S';
                }
                if(storage[i][j] == 'P'){
                    if(storage[i-1][j] == 'R') temp[i-1][j] = 'P';
                    if(storage[i+1][j] == 'R') temp[i+1][j] = 'P';
                    if(storage[i][j-1] == 'R') temp[i][j-1] = 'P';
                    if(storage[i][j+1] == 'R') temp[i][j+1] = 'P';
                }
            }
        }
        // delivery
        for(i = 1; i <= r; i++){
            for(j = 1; j <= c; j++){
                storage[i][j] = temp[i][j];
            }
        }
    }
    for(i = 1; i <= r; i++){
        for(j = 1; j <= c; j++){
            printf("%c", storage[i][j]);
        }
        printf("\n");
    }
    return 0;

}