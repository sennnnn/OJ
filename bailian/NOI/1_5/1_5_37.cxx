/*
    题目名字: 雇佣兵
    题目编号: 6042
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int main(){
    int M, N, X;
    int N_add;
    scanf("%d %d %d", &M, &N, &X);
    while(X != 0 && N <= M){
        N_add = M/N;
        if(M%N == 0) X -= M/N;
        else X = X - M/N - 1;
        if(X < 0) break;
        N += N_add;
    }
    printf("%d\n", N);
    return 0;
}