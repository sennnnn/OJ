/*
    题目名字: 回文子串
    题目编号: 7603
    日期: 2020 年 6 月 26 日
*/

#include <stdio.h>
#include <string.h>

bool isPa(char *s, int start, int end){
    end = end - 1;
    for(int k = start; k <= (start+end)/2; k++){
        if(s[k] != s[start+end-k]) return false;
    }
    return true;
}

void show(char *s, int start, int end){
    for(int i = start; i < end; i++){
        printf("%c", s[i]);
    }
    printf("\n");
}

int main(){
    int len, count;
    char s[600];
    scanf("%s", s);
    len = strlen(s); count = 0;
    for(int i = 2; i <= len; i++){
        for(int j = 0; j < len-i+1; j++){
            if(isPa(s, j, j+i)){
                show(s, j, j+i);
            }
        }
    }
}