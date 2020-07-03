/*
    题目名字: 铺地毯
    备注: 模拟，枚举，NOIP 提高组
    日期: 2020 年 7 月 3 日
*/

#include <stdio.h>

int main(){
    int xy[10010][4];
    int tx, ty;
    int n, k;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d %d %d %d", &xy[i][0], &xy[i][1], &xy[i][2], &xy[i][3]);
    }
    scanf("%d %d", &tx, &ty);
    k = -1;
    for(int i = 1; i <= n; i++){
        if(xy[i][0] <= tx && tx <= xy[i][0] + xy[i][2])
            if(xy[i][1] <= ty && ty <= xy[i][1] + xy[i][3])
                k = i;
    }
    printf("%d\n", k);
}