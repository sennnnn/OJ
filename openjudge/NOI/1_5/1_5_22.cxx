/*
    题目名字: 津津的储蓄计划
    题目编号: 7903
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>

int main(){
    int count;
    int remain;
    int record[12];
    for(int i = 0; i < 12; i++){
        scanf("%d", &record[i]);
    }
    remain = 0; count = 0;
    for(int i = 0; i < 12; i++){
        remain = 300 + remain - record[i];
        if(remain < 0) {printf("%d\n", -1*(i+1)); return 0;}
        count += remain/100 * 100;
        remain = remain % 100;
        // printf("%d %d %d\n", i, remain, count);
    }
    printf("%d\n", (int)(1.2*count) + remain);

}