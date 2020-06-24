/*
    题目名字: 求分数序列和
    题目编号: 7718
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int main(){
    int p, q, t;
    int n;
    double item;
    p = 1; q = 2; item = 0.0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        item += (double)q/(double)p;
        t = q;
        q = q + p;
        p = t;
    }
    printf("%.4f\n", item);
}