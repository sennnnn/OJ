/*
    题目名字: 求特殊自然数
    题目编号: 7918
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert(int num, int base, char *s){
    int len = 0;
    char temp;
    while(num > 0){
        s[len++] = num % base + '0';
        num /= base;
    }
    for(int i = 0; i < len/2; i++){
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;
    }
    s[len] = '\0';
}

bool judge(char *s1, char *s2){
    int len1, len2;
    len1 = strlen(s1); 
    len2 = strlen(s2);
    if(len1 != 3 || len2 != 3) return false;
    for(int i = 0; i < 3; i++){
        if(s1[i] != s2[3-i-1]) return false;
    }
    return true;
}

int main(){
    char s1[100], s2[100];
    for(int i = 10; i <= 999; i++){
        memset(s1, 0, sizeof(s1)); memset(s2, 0, sizeof(s2));
        convert(i, 7, s1); convert(i, 9, s2);
        if(judge(s1, s2)){
            printf("%d\n", i);
            printf("%s\n", s1);
            printf("%s\n", s2);
        }
    }
}