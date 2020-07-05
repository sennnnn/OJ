/*
    题目名字: 图像旋转
    题目编号: 8065
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m;
    char storage[110][110], new_stor[110][110];
    scanf("%d %d", &n, &m);
    memset(storage, 0, sizeof(storage)); memset(new_stor, 0, sizeof(new_stor));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &storage[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            new_stor[j][n+1-i] = storage[i][j];
        }
    }
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            printf("%d ", new_stor[i][j]);
        }
        printf("\n");
    }
    return 0;
}