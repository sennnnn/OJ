/*
    题目名字: 救援
    题目编号: 7534
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <math.h>

int main(){
    int n;
    int people_n;
    double x, y, res;
    scanf("%d", &n);
    res = 0.0;
    for(int i = 0; i < n; i++){
        scanf("%lf %lf %d", &x, &y, &people_n);
        res += 2*sqrt(x*x + y*y)/50.0;
        res += people_n*1.5; 
    }
    printf("%d\n", (int)ceil(res));
}