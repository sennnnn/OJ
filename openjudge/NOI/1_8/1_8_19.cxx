/*
    题目名字: 肿瘤检测
    题目编号: 1679
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int storage[110][110];
    int N, area, len, i, j;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &storage[i][j]);
        }
    }
    len = 0; area = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            if(storage[i][j] <= 50) {
                if(i == 0 || i == N-1 || j == 0 || j == N-1) len++;
                else if(storage[i+1][j] > 50 || storage[i-1][j] > 50 || storage[i][j+1] > 50 || storage[i][j-1] > 50) len++;
                area++;
            }
        }
    }
    printf("%d %d\n", area, len);
}