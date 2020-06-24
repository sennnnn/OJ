/*
    题目名字: 校门外的树
    题目编号: 7905
    日期: 2020 年 6 月 23 日
    备注: 主要从 0 ~ n 考虑, 实际上最初应该是有 n + 1 棵树
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int road[10001];
    int L, M;
    int start[100], end[100];
    int count;
    scanf("%d %d", &L, &M);
    for(int i = 0; i <= L; i++){
        road[i] = 1;
    }
    for(int i = 0; i < M; i++){
        scanf("%d %d", &start[i], &end[i]);
        for(int j = start[i]; j <= end[i]; j++){
            road[j] = 0;
        }
    }
    count = 0;
    for(int i = 0; i <= L; i++){
        if(road[i] == 1) count++;
    }
    printf("%d\n", count);
}