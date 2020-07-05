/*
    题目名字: 密码翻译
    题目编号: 8173
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char s[100];
    int len;
    scanf("%[^\n]", s);
    len = strlen(s);
    for(int i = 0; i < len; i++){
        if(s[i] == 'z') printf("a");
        else if(s[i] == 'Z') printf("A");
        else if(s[i] >= 'a' && s[i] < 'z' || s[i] >= 'A' && s[i] < 'Z') printf("%c", s[i]+1);
        else printf("%c", s[i]);
    }
    printf("\n");
}