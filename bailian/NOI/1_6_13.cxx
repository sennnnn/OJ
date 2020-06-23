/*
    题目名字: 大整数的因子
    题目编号: 1927
    日期: 2020 年 6 月 23 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char c[31];
    char o[31];
    int len;
    int k;
    int temp;
    int io;
    int count;
    scanf("%s", c);
    len = strlen(c);
    count = 0;
    for(k = 2; k <= 9; k++){
        temp = 0;
        io = 0;
        for(int i = 0; i < len; i++){
            // printf("1");
            temp = temp*10 + (c[i] - '0');
            o[io++] = temp/k + '0';
            temp = temp%k;
        }
        if(temp == 0) {
            count++;
            printf("%d ", k);
        }
    }
    if(count == 0) printf("none");
    printf("\n");
}