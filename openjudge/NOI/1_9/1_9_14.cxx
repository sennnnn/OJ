/*
    题目名字: 铺地毯
    题目编号: 7921
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, carpet[10010][4];
    int x, y, up;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &carpet[i][0], &carpet[i][1], &carpet[i][2], &carpet[i][3]);
    }
    scanf("%d %d", &x, &y);
    up = -1;
    for(int i = 0; i < n; i++){
        if(x >= carpet[i][0] && x <= carpet[i][0] + carpet[i][2] && y >= carpet[i][1] && y <= carpet[i][1] + carpet[i][3]) up = i+1;
    }
    printf("%d\n", up);
}