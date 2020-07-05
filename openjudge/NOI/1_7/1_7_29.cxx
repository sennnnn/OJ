/*
    题目名字: ISBN 号码
    题目编号: 7911
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    char s[20];
    int storage[20], len, i, j, res;
    scanf("%[^\n]", s);
    len = strlen(s); i = 0; j = 0; res = 0;
    for(; i < len; i++){
        if(s[i] >= '0' && s[i] <= '9') storage[j++] = s[i] - '0';
        if(i == len-1 && s[i] == 'X') storage[j++] = 10;
    }
    for(int i = 0; i < j-1; i++){
        res += storage[i]*(i+1);
    }
    if(res%11 == storage[j-1]) printf("Right\n");
    else{
        if(res%11 == 10) s[len-1] = 'X';
        else s[len-1] = res%11 + '0';
        printf("%s\n", s);
    }
}