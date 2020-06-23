/*
    题目名字: 大整数加法
    题目编号: 1982
    日期: 2020 年 6 月 23 日
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char a[301], b[301];
    int d[300]={0}, f[300]={0}, e[300]={0};
    int l1, l2;
    int i, j;
    scanf("%s", a);
    scanf("%s", b);
    l1 = strlen(a);
    l2 = strlen(b);
    j = 0;
    for(i = l1-1; i >= 0; i--){
        d[j++] = a[i] - '0';
    }
    j = 0;
    for(i = l2-1; i >= 0; i--){
        f[j++] = b[i] - '0';
    }
    j = 0;
    for(; j < 299; j++){
        e[j] += d[j] + f[j];
        if(e[j] >= 10){
            e[j+1] += e[j] / 10;
            e[j] = e[j] % 10;
        }
    }
    while(e[j] == 0 && j != 0) j--;
    for(i = j; i >= 0; i--) printf("%d", e[i]);
    printf("\n");
    return 0;
}