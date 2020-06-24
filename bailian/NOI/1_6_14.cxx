/*
    题目名字: 求 10000 以内 n 的阶乘
    题目编号: 1733
    日期: 2020 年 6 月 23 日
    备注: 还是高精度乘法
*/

#include <stdio.h>
#include <string.h>

void init(int n, char *s){
    int index = 0;
    while(n > 0){
        s[index++] = n%10;
        n /= 10;
    }
}

int main(){
    int n;
    int s[500000];
    int i, j;
    scanf("%d", &n);
    memset(s, 0, sizeof(s));
    s[0] = 1; s[1] = 1;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= s[0]; j++){
            s[j] *= i;
        }
        for(j = 1; j <= s[0]; j++){
            s[j+1] += s[j] / 10;
            s[j] = s[j] % 10;
        }
        if(s[j] > 0){
            while(s[j] >= 10){
                s[j+1] += s[j] / 10;
                s[j] = s[j] % 10;
                j++;
            }
            s[0] = j;
        }
    }
    for(int i = s[0]; i >= 1; i--) printf("%d", s[i]);
    printf("\n");
}