/*
    题目名字: 角谷猜想
    题目编号: 7784
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>

int main(){
    long long n;
    scanf("%d", &n);
    while(n != 1){
        if(n%2 == 1){
            printf("%lld*3+1=%lld\n", n, n*3+1);
            n = n*3+1;
        }else{
            printf("%lld/2=%lld\n", n, n/2);
            n = n/2;
        }
    }
    printf("End\n");
    return 0;
}