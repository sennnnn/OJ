/*
    题目名字: 字符串 p 型编码
    题目编号: 6680
    日期: 2020 年 6 月 26 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int len, count;
    char s[1010], temp;
    scanf("%s", s);
    len = strlen(s); count = 1; temp = s[0];
    if(len == 1) {printf("%d%c", count, temp); return 0;}
    for(int i = 1; i <= len; i++){
        if(temp == s[i] && s[i] != '\n') count++;
        else{
            printf("%d%c", count, temp);
            temp = s[i];
            count = 1;
        }
    }
    printf("\n");
}