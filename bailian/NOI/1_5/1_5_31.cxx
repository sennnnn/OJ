/*
    题目名字: 开关灯
    题目编号: 7597
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int flag[5010];
    int N, M;
    memset(flag, 0, sizeof(flag));
    scanf("%d %d", &N, &M);
    for(int i = 2; i <= M; i++){
        if(i == 2){
            for(int j = 1; j <= N; j++){
                if(j%2 == 0) flag[j] = 1;
            }
        }else{
            for(int j = 1; j <= N; j++){
                if(j%i == 0) flag[j] = !flag[j];
            }
        }
    }
    int ifstart = 1;
    for(int i = 1; i <= N; i++){
        if(flag[i] == 0) {
            if(ifstart){
                printf("%d", i);
                ifstart = 0;
            }else printf(",%d", i);
        }
    }
    printf("\n");
}