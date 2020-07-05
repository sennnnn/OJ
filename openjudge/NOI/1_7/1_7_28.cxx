/*
    题目名字: 单词倒排
    题目编号: 6246
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int len, w_s, w_e, count;
    int i, j, g_i;
    char s[200];
    char get[200][200];
    scanf("%[^\n]", s);
    len = strlen(s); w_s = 0; w_e = 0; count = 0;
    for(i = 0; i <= len; i++){
        if(s[i] == ' ' || s[i] == '\0'){
            w_s = w_e;
            w_e = i - 1;
            g_i = 0;
            for(j = w_s; j <= w_e; j++){
                get[count][g_i++] = s[j];
            }
            get[count][g_i] = '\0';
            count++;
            w_e = i + 1;
        }
    }
    for(i = count-1; i >= 0; i--){
        printf("%s ", get[i]);
    }
    printf("\n");
}