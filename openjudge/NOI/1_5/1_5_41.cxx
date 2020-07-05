/*
    题目名字: 数字统计
    题目编号: 7916
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int calculate(int num){
    int count = 0;
    while(num > 0){
        if(num%10 == 2) count++;
        num /= 10;
    }
    return count;
}

int main(){
    int L, R;
    int count;
    scanf("%d %d", &L, &R);
    count = 0;
    for(int i = L; i <= R; i++){
        count += calculate(i);
    }
    printf("%d\n", count);
}