/*
    题目名字: 数字反转
    题目编号: 7919
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>
#include <math.h>

int abs(int num){
    if(num < 0) return -1*num;
    else return num;
}

int main(){
    int N;
    int N_spl[1000], count;
    int newn, flag;
    scanf("%d", &N);
    if(N < 0) flag = -1;
    else flag = 1;
    N = abs(N);
    count = 0;
    while(N > 0){
        N_spl[count++] = N % 10;
        N /= 10;
    }
    newn = 0;
    for(int i = 0; i < count; i++){
        newn = newn*10 + N_spl[i];
    }
    printf("%d\n", flag*newn);
    return 0;
}