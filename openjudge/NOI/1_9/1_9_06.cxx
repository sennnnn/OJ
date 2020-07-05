/*
    题目名字: 笨小猴
    题目编号: 7912
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int count[129];

bool ifPrimer(int temp){
    if(temp <= 1) return false;
    for(int i = 2; i <= sqrt(temp); i++){
        if(temp%i == 0) return false;
    }
    return true;
}

int main(){
    int maxn, minn, len;
    char s[110];
    scanf("%s", s);
    len = strlen(s);
    minn = 1111; maxn = -1;
    for(int i = 0; i < len; i++){
        count[s[i]]++;
    }
    for(int i = 0; i < len; i++){
        if(count[s[i]] > maxn) maxn = count[s[i]];
        if(count[s[i]] < minn) minn = count[s[i]];
    }
    if(ifPrimer(maxn-minn)) printf("Lucky Word\n%d\n", maxn-minn);
    else printf("No Answer\n0\n");
}