/*
    题目名字: 计算多项式的值
    题目编号: 7583
    日期: 2020 年 6 月 24 日
    备注: 其实就是计算等比数列
*/

#include <stdio.h>
#include <math.h>

int main(){
    double a;
    int n;
    scanf("%lf %d", &a, &n);
    if(a == 1.0) printf("%.2f\n", (double)(n+1));
    else{
        printf("%.2f\n", (pow(a, (double)(n+1)) - 1)/(a - 1));
    }
}