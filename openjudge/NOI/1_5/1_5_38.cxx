/*
    题目名字: 计算多项式的导函数
    题目编号: 4974
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int main(){
    int N;
    int n;
    int C[101];
    scanf("%d", &n);
    for(int i = 0; i < n+1; i++){
        scanf("%d", &C[i]);
    }
    if(n == 0) printf("0\n");
    for(int i = 0; i < n; i++){
        printf("%d ", (n-i)*C[i]);
    }
    printf("\n");
}
