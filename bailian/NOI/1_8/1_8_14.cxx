/*
    题目名字: 扫雷游戏地雷数计算
    题目编号: 8067
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m, i, j, k;
    char storage[110][110], flag[110][110];
    memset(storage, 0, sizeof(storage)); memset(flag, 0, sizeof(flag));
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%s", storage[i]+1);
        strcpy(flag[i]+1, storage[i]+1);
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            if(storage[i][j] == '?'){
                flag[i][j] = flag[i][j] - '?' + '0';
                if(storage[i-1][j-1] == '*') flag[i][j] += 1;
                if(storage[i-1][j]   == '*') flag[i][j] += 1;
                if(storage[i-1][j+1] == '*') flag[i][j] += 1;
                if(storage[i][j+1]   == '*') flag[i][j] += 1;
                if(storage[i+1][j+1] == '*') flag[i][j] += 1;
                if(storage[i+1][j]   == '*') flag[i][j] += 1;
                if(storage[i+1][j-1] == '*') flag[i][j] += 1;
                if(storage[i][j-1]   == '*') flag[i][j] += 1;
            }
        }
    }
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            printf("%c", flag[i][j]);
        }
        printf("\n");
    }
}