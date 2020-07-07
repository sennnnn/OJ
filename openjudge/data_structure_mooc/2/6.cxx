/*
    题目名字: 大整数乘法
    编号: 7120
    日期: 2020 年 7 月 7 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char s1[210];
    char s2[210];
    int ss1[210];
    int ss2[210];
    int res[410];
    int len1, len2;
    memset(s1, 0, sizeof(s1)); 
    memset(s2, 0, sizeof(s2)); 
    memset(res, 0, sizeof(res));
    scanf("%s %s", s1, s2);
    len1 = strlen(s1);
    len2 = strlen(s2);
    for(int i = len1-1, j = 0; i >= 0; i--, j++){
        ss1[j] = s1[i] - '0';
    }
    for(int i = len2-1, j = 0; i >= 0; i--, j++){
        ss2[j] = s2[i] - '0';
    }

    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            res[i+j] += ss1[i]*ss2[j];
            res[i+j+1] += res[i+j]/10;
            res[i+j] %= 10;
        }
    }
    int index = 409;
    while(res[index] == 0 && index != 0) index--;
    for(int i = index; i >= 0; i--){
        printf("%d", res[i]);
    }
    printf("\n");
    return 0;
}