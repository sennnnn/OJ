/*
    题目名字: 字符串的展开
    题目编号: 7910
    日期: 2020 年 6 月 26 日
*/

#include <stdio.h>
#include <string.h>

int judge(char temp){
    if(temp >= '0' && temp <= '9') return 1;
    if(temp >= 'a' && temp <= 'z') return 2;
    return 0;
}

void lower(char &a){
    if(a >= 'A' && a <= 'Z') a -= 'A' - 'a';
}

void capital(char &a){
    if(a >= 'a' && a <= 'z') a += 'A' - 'a';
}

void process(char a, char b, char *res, int &count, int p1, int p2, int p3){
    int index;
    index = 0;
    for(int i = a; i <= b; i++){
        if(i == a || i == b){
            res[index++] = (char)i;
            continue;
        }
        for(int j = 0; j < p2; j++) res[index++] = (char)i;
    }
    char temp;
    if(p3 == 2){
        for(int i = 1; i <= (index-1)/2; i++){
            temp = res[i];
            res[i] = res[index-1-i];
            res[index-1-i] = temp;
        }
    }
    for(int i = 1; i < index-1; i++){
        if(p1 == 1) lower(res[i]);
        if(p1 == 2) capital(res[i]);
        if(p1 == 3) res[i] = '*';
    }
    count += index;
}

int main(){
    int p1, p2, p3, len, count;
    char s[110], res[50000];
    scanf("%d %d %d", &p1, &p2, &p3);
    scanf("%s", s);
    len = strlen(s); count = 0;
    for(int i = 0; i < len; i++){
        res[count++] = s[i];
        if(s[i] == '-' && i != len-1){
            if(judge(s[i-1]) == 0 || judge(s[i+1]) == 0) continue;
            if(judge(s[i-1]) == judge(s[i+1]) && s[i-1] < s[i+1]){
                count -= 2;
                process(s[i-1], s[i+1], res+count, count, p1, p2, p3);
                // for(int j = s[i-1]; j <= s[i+1]; j++){
                //     res[count++] = (char)j;
                // }
                i++;
            }
        }
    }
    res[count] = '\0';
    printf("%s\n", res);
}