/*
    题目名字: 加密的病历单
    题目编号: 8160
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

char process(char c){
    if(c >= 'a' && c <= 'z') {
        if(c + 3 > 'z') c = 'a' + (2 - 'z' + c);
        else c += 3;
        c += 'A' - 'a';
    }else if(c >= 'A' && c <= 'Z') {
        if(c + 3 > 'Z') c = 'A' + (2 - 'Z' + c);
        else c += 3;
        c -= 'A' - 'a';
    }
    return c;
}

int main(){
    char s[100], res[100];
    int len, i, j;
    memset(s, 0, sizeof(s)); memset(res, 0, sizeof(res));
    scanf("%s", s);
    len = strlen(s);
    // lower case and capital reverse & string reverse
    j = 0;
    for(i = len-1; i >= 0; i--){
        res[j++] = process(s[i]);
    }
    for(i = 0; i < len; i++){
        printf("%c", res[i]);
    }
    printf("\n");
    return 0;
}