/*
    题目名字: 计算分数加减表达式的值
    题目编号: 7584
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

double item(int num){
    double temp;
    temp = (double)num;
    temp = 1.0/temp;
    if(num%2 == 0) temp *= -1;
    return temp;
}

int main(){
    int n;
    double res;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        res += item(i);
    }
    printf("%.4f\n", res);

}