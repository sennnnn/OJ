/*
    题目名字: 二维数组回形遍历
    题目编号: 7545
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    int i, j, k, con, R, C;
    int storage[110][110];
    int flag[110][110];
    scanf("%d %d", &R, &C);
    memset(flag, 0, sizeof(flag));
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            scanf("%d", &storage[i][j]);
            flag[i][j] = 2;
        }
    }
    i = 0; j = 0; k = 0; con = 0;
    while(k < R*C){
        if(flag[i][j] == 2){
            k++;
            flag[i][j] = 1;
            printf("%d\n", storage[i][j]);
        }else{
            if(flag[i + di[con]][j + dj[con]] != 2){
                con++; con %= 4;
                i += di[con];
                j += dj[con];
            }else{
                i += di[con];
                j += dj[con];
            }
        }
    }
    return 0; 
}