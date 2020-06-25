/*
    题目名字: 单词翻转
    题目编号: 6255
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int w_s, w_e;
    char s[600], temp;
    scanf("%[^\n]", s);
    n = strlen(s);
    w_s = 0; w_e = 0;
    for(int i = 0; i <= n; i++){
        if(s[i] == ' ' || s[i] == '\0'){
            w_s = w_e;
            w_e = i-1;
            for(int j = w_s; j <= (w_e+w_s)/2; j++){
                temp = s[j];
                s[j] = s[w_s + w_e - j];
                s[w_s + w_e - j] = temp;
            }
            w_e = i+1;
        }
    }
    for(int i = 0; i < n; i++){
        printf("%c", s[i]);
    }
    printf("\n");
    return 0;
}