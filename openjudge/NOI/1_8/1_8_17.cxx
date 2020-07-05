/*
    题目名字: 最好的草
    题目编号: 2391
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int R, C, i, j, count;
    char storage[1000][110];
    scanf("%d %d", &R, &C);
    memset(storage, 0, sizeof(storage));
    getchar();
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            scanf("%c", &storage[i][j]);
        }
        getchar();
    }
    count = 0;
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            if(storage[i][j] == '#'){
                if(storage[i+1][j] == '#') storage[i+1][j] = '.';
                else if(storage[i-1][j] == '#') storage[i-1][j] = '.';
                else if(storage[i][j+1] == '#') storage[i][j+1] = '.';
                else if(storage[i][j-1] == '#') storage[i][j-1] = '.';
                storage[i][j] = '.';
                count++;
            }
        }
    }
    printf("%d\n", count);
}