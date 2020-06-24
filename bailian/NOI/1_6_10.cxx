/*
    题目名字: 大整数加法
    题目编号: 1982
    日期: 2020 年 6 月 23 日
    备注: 主要考虑三种前置零的情况: 00 + 00, 01 + 00, 01 + 01
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char add1[301], add2[301];
    int int1[300], int2[300], res[300];
    int l1, l2;
    int i, j;
    scanf("%s", add1);
    scanf("%s", add2);
    l1 = strlen(add1);
    l2 = strlen(add2);
    memset(int1, 0, sizeof(int1));
    memset(int2, 0, sizeof(int2));
    memset(res, 0, sizeof(res));
    // 首先将数值的字符串反转之后保存为整型数组
    j = 0;
    for(i = l1-1; i >= 0; i--){
        int1[j++] = add1[i] - '0';
    }
    j = 0;
    for(i = l2-1; i >= 0; i--){
        int2[j++] = add2[i] - '0';
    }
    // 直接把范围开大这样就不用过多考虑计算出来的位数是多少的问题
    j = 0;
    for(; j < 299; j++){
        res[j] += int1[j] + int2[j];
        if(res[j] >= 10){
            res[j+1] += res[j] / 10;
            res[j] = res[j] % 10;
        }
    }
    // 去除前导零
    while(res[j] == 0 && j != 0) j--;
    for(i = j; i >= 0; i--) printf("%d", res[i]);
    printf("\n");
    return 0;
}