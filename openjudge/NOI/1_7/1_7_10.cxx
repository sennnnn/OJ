/*
    题目名字: 简单密码
    题目编号: 1769
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int len;
    char s[300];
    scanf("%[^\n]", s);
    len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] >= 'A' && s[i] <= 'Z'){
            if(s[i] - 5 < 'A'){
                printf("%c", 'Z' - (4 - s[i] + 'A'));
            }else{
                printf("%c", s[i] - 5);
            }
        }else{
            printf("%c", s[i]);
        }
    }
}