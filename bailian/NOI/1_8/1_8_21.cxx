/*
    题目名字: 二维数组右上左下遍历
    题目编号: 6376
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int R, C, i, j, k, round;
    int di[2] = {-1, +1};
    int dj[2] = {+1, -1};
    int storage[110][110], flag[110][110];
    scanf("%d %d", &R, &C);
    memset(storage, 0, sizeof(storage)); memset(flag, 0, sizeof(flag));
    for(i = 1; i <= R; i++){
        for(j = 1; j <= C; j++){
            scanf("%d", &storage[i][j]);
            flag[i][j] = 1;
        }
    }
    i = 1; j = 1; k = 0; round = 0;
    while(k < R*C){
        if(flag[i][j] == 1){
            flag[i][j] = 0;
            k++;
            printf("%d\n", storage[i][j]);
        }else{
            if(flag[i + 1][j - 1] != 1){
                if(j < C) {
                    j++;
                    i = 0;
                }else {
                    i++;
                    j = C;
                }
            }else{
                i += 1;
                j -= 1;
            }
        }
    }
    return 0;
}