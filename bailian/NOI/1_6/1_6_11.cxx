/*
    题目名字: 大整数减法
    题目编号: 1738
    日期: 2020 年 6 月 23 日
    备注: 没有多余的前导零, 直接模拟列竖式减法就好了
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char s1[201], s2[201], o[201];
    int n1, n2;
    scanf("%s", s1); scanf("%s", s2);
    n1 = strlen(s1); n2 = strlen(s2);
    int borrow;
    int i1, i2, io;
    i1 = n1 - 1; i2 = n2 - 1; io = 0;
    borrow = 0;
    for(; i1 >= 0; i1--, i2--){
        s1[i1] -= borrow;
        // printf("%c %c\n", s1[i1], s2[i2]);
        // printf("%d %d\n", i1, i2);
        if(i2 >= 0){
            if(s1[i1] < s2[i2]){
                borrow = 1;
                o[io] = 10 + s1[i1] - s2[i2] + '0';
            }else{
                borrow = 0;
                o[io] = s1[i1] - s2[i2] + '0';
            }
        }else{
            borrow = 0;
            o[io] = s1[i1];
        }
        io++;
    }
    for(int i = io - 1; i >= 0; i--){
        printf("%c", o[i]);
    }
    printf("\n");
}
