/*
    题目名字: Charm Bracelet
    编号: POJ 3624
    日期: 2020 年 7 月 12 日
*/


/* 滚动数组 + 0-1 dp*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct object{
    int value;
    int volume;
}object;

int N, M;
object objects[3510];
int dp[13010];

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    memset(dp, 0, sizeof(dp));
    scanf("%d %d", &N, &M);
    for(int i = 1; i <= N; i++){
        scanf("%d %d", &objects[i].volume, &objects[i].value);
    }
    for(int i = 0; i <= M; i++){
        if(objects[1].volume > i) continue;
        dp[i] = objects[1].value;
    }
    for(int i = 2; i <= N; i++){
        for(int j = M; j >= 0; j--){
            if(objects[i].volume > j) continue;
            dp[j] = max(objects[i].value + dp[j - objects[i].volume], dp[j]);
        }
    }
    printf("%d\n", dp[M]);
}