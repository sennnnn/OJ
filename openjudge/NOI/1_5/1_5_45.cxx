/*
    题目名字: 金币
    题目编号: 7878
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int main(){
    int n;
    int days, times;
    int count;
    scanf("%d", &n);
    
    count = 0; days = 0; times = 1;
    for(;;){
        if(days + times <= n){
            days += times;
            count += times*times;
            times++;
        }else{
            count += (n - days)*times;
            break;
        }
    }
    printf("%d\n", count);
}