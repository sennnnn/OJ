/*
    题目名字: 画矩形
    题目编号: 8183
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>

int main(){
    int r, c, sign;
    char flag;
    scanf("%d %d %c %d", &r, &c, &flag, &sign);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            if(sign) printf("%c", flag);
            else{
                if(i == 0 || i == r-1) printf("%c", flag);
                else{
                    if(j == 0 || j == c-1) printf("%c", flag);
                    else printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}