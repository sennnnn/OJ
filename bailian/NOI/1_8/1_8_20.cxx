/*
    题目名字: 反反复复
    题目编号: 1041
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char storage[110][110];
    int R, C, len;
    int i, j, k, dj;
    char s[210];
    scanf("%d", &C);
    scanf("%s", s);
    len = strlen(s);
    // 输入
    i = 0; j = 0; k = 0; dj = 1; R = 0;
    while(k < len){
        storage[i][j] = s[k];
        k++; j += dj;
        if(j == C && dj == 1){
            dj *= -1;
            j--;
            i++;
            R++;
        }
        if(j == -1 && dj == -1){
            dj *= -1;
            j++;
            i++;
            R++;
        }
    }
    for(j = 0; j < C; j++){
        for(i = 0; i < R; i++){
            printf("%c", storage[i][j]);
        }
    }
    printf("\n");
    return 0;
}