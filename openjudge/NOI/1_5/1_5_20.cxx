/*
    题目名字: 弹跳球高度的计算
    题目编号: 2143
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>

int main(){
    int count;
    double n;
    double res;
    scanf("%lf", &n);
    res = 0.0; count = 0;
    for(; count < 10; count++){
        res += n;
        n /= 2;
        if(count != 9) res += n;
    }
    printf("%g\n", res);
    printf("%g\n", n);
}