/*
    题目名称: 计算 2 的 N 次方
    题目编号: 1811
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int res[300];
    int n;
    int i, j;
    scanf("%d", &n);
    memset(res, 0, sizeof(res));
    res[0] = 1; res[1] = 1;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= res[0]; j++) res[j] *= 2;
        for(j = 1; j <= res[0]; j++) {
            res[j+1] += res[j] / 10;
            res[j]   = res[j] % 10;
        }
        if(res[j] > 0){
            while(res[j] >= 10){
                res[j+1] += res[j] / 10;
                res[j]   = res[j] % 10;
                j++;
            }
            res[0] = j;
        }
    }
    for(int i = res[0]; i >= 1; i--) printf("%d", res[i]);
    printf("\n");
}