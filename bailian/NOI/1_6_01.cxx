/*
    题目名字: 与指定数字相同的数的个数
    题目编号: 7609
    日期: 2020 年 6 月 23 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, m;
    int l[100];
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d", &l[i]);
    }
    scanf("%d", &m);
    int count = 0;
    for(int i = 0; i < N; i++){
        if(l[i] == m) count++;
    }
    printf("%d\n", count);
}