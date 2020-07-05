/*
    题目名字: 制作蛋糕
    题目编号: 19630
    日期: 2020 年 7 月 4 日
*/

#include <stdio.h>
#include <string.h>

typedef struct bancake{
    int self = 2;
    int mf = 250;
    int sg = 75;
    int bu = 100;
    int value = 400;
    int num;
}bancake;

typedef struct chocake{
    int self = 75;
    int mf = 200;
    int sg = 150;
    int bu = 150;
    int value = 450;
    int num;
}chocake;

int main(){
    int mf, ban, sg, bu, co;
    int max_value, suit_i, suit_j;
    scanf("%d %d %d %d %d", &mf, &ban, &sg, &bu, &co);
    bancake banana;
    chocake chocola;
    banana.num = ban / banana.self;
    chocola.num = co / chocola.self;
    max_value = -1;
    for(int i = 0; i <= banana.num; i++){
        for(int j = 0; j <= chocola.num; j++){
            if(banana.mf*i + chocola.mf*j <= mf && banana.sg*i + chocola.sg*j <= sg && banana.bu*i + chocola.bu*j <= bu){
                if(banana.value*i + chocola.value*j > max_value){
                    max_value = banana.value*i + chocola.value*j;
                    suit_i = i;
                    suit_j = j;
                }
            }
        }
    }
    printf("%d\n%d\n%d\n", max_value, suit_i, suit_j);
}