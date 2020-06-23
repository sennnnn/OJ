/*
    题目名称: 阶乘和
    题目编号: 7890
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int res[5000];
    int res_temp[5000];
    int n;
    int i, j;

    memset(res, 0, sizeof(res));
    memset(res_temp, 0, sizeof(res_temp));
    scanf("%d", &n);

    for(i = 1; i <= n; i++){
        int k, len;
        int temp[5000];
        memset(temp, 0, sizeof(temp));
        len = 1; temp[0] = 1;
        for(j = 1; j <= i; j++){
            for(k = 0; k < len; k++) temp[k] = temp[k]*j;
            for(k = 0; k < len; k++) {
                temp[k+1] += temp[k] / 10;
                temp[k]   = temp[k] % 10;
            }
            if(temp[k] > 0){
                while(temp[k] >= 10){
                    temp[k+1] += temp[k] / 10;
                    temp[k]   = temp[k] % 10;
                    k++;
                }
                len = k+1;
            }
        }
        // 单个阶乘计算
        // for(int i = 0; i < len; i++){
        //     printf("%d", temp[i]);
        // }
        // 对阶乘的累加
        for(int index = 0; index < len; index++){
            res[index] += temp[index];
            if(res[index] >= 10){
                res[index+1] += res[index] / 10;
                res[index] = res[index] % 10;
            }
        }
        // 累加后结果查看
        // printf(" ");
        // for(int i = 0; i < len; i++){
        //     printf("%d", res[i]);
        // }
        // printf("\n");
    }

    i = 5000;
    while(res[i] == 0 && i != 0) i--;
    for(; i >= 0; i--){
        printf("%d", res[i]);
    }
    printf("\n");
}