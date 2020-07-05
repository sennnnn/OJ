/*
    题目名字: 肿瘤面及
    题目编号: 1715
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char storage[1010][1010];
    int N, i, j, i_min, i_max, j_min, j_max, count;
    scanf("%d", &N);
    i_min = N; i_max = -1; j_min = N; j_max = -1; count = 0;
    for(i = 0; i < N; i++){
        for(j = 0; j < N; j++){
            scanf("%d", &storage[i][j]);
            if(storage[i][j] == 0){
                if(i < i_min) i_min = i;
                if(i > i_max) i_max = i;
                if(j < j_min) j_min = j;
                if(j > j_max) j_max = j;
            }
        }
    }
    for(i = i_min + 1; i < i_max; i++){
        for(j = j_min + 1; j < j_max; j++){
            count++;
        }
    }
    printf("%d\n", count);
}