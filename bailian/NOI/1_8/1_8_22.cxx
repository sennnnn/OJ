/*
    题目名字: 幻方
    题目编号: 7207
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, i, j, k, R, C;
    int storage[100][100], flag[100][100];
    scanf("%d", &N);
    memset(storage, 0, sizeof(storage)); memset(flag, 0, sizeof(flag));
    R = 2*N-1; C = 2*N-1;
    // 预处理
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            flag[i][j] = 1;
        }
    }
    // 开始遍历
    i = 0; j = C/2; k = 0;
    while(k < R*C){
        if(flag[i][j] == 1){
            k++;
            flag[i][j] = 0;
            storage[i][j] = k;
        }else{
            if(flag[(i - 1 + R)%R][(j + 1)%C] != 1){
                i = (i + 1)%R;
            }else{
                i = (i - 1 + R)%R;
                j = (j + 1)%C;
            }
        }
    }
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%d ", storage[i][j]);
        }
        printf("\n");
    }
    return 0;
}
