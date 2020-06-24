/*
    题目名字: 求出 e 的值
    题目编号: 1711
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

double factorial(int num){
    if(num == 0) return 1.0;
    double accu = 1.0;
    for(int i = 2; i <= num; i++){
        accu *= i;
    }
    return accu;
}

int main(){
    int n;
    double res;
    double temp;
    scanf("%d", &n);
    res = 0;
    for(int i = 0; i <= n; i++){
        res += 1.0/factorial(i);
    }
    printf("%.10f", res);
}