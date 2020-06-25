/*
    题目名字: 潜伏者
    题目编号: 7915
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

char hash[129];
char reverse_hash[129];

int main(){
    int len, iffail;
    char s1[200], s2[200], s3[200], temp;
    scanf("%s", s1); scanf("%s", s2); scanf("%s", s3);
    memset(hash, 0, sizeof(hash));
    if(strlen(s1) != strlen(s2)) return 0;
    len = strlen(s1);
    iffail = 0;
    for(int i = 0; i < len; i++){
        temp = s1[i];
        if(hash[temp] == 0 || hash[temp] == s2[i]) hash[temp] = s2[i];
        else {iffail = 1; break;}
        temp = s2[i];
        if(reverse_hash[temp] == 0 || reverse_hash[temp] == s1[i]) reverse_hash[temp] = s1[i];
        else {iffail = 1; break;}
    }
    for(int i = 'A'; i <= 'Z'; i++){
        if(hash[i] == 0) {iffail = 1; break;}
    }
    if(iffail) printf("Failed\n");
    else{
        len = strlen(s3);
        for(int i = 0; i < len; i++){
            printf("%c", hash[s3[i]]);
        }
        printf("\n");
    }
}