/*
    题目名字: 陶陶摘苹果
    题目编号: 7904
    日期: 2020 年 6 月 23 日
*/

#include <stdio.h>


int main(){
    int count;
    int height[10];
    int taotao;
    for(int i = 0; i < 10; i++){
        scanf("%d", &height[i]);
    }
    scanf("%d", &taotao);
    count = 0;
    for(int i = 0; i < 10; i++){
        if(taotao + 30 >= height[i]) count++;
    }
    printf("%d\n", count);
}