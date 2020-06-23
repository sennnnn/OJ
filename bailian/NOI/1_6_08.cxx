/*
    题目名字: 石头剪刀布
    题目编号: 4973
    日期: 2020 年 6 月 23 日
*/

#include <stdio.h>

int judge(int a, int b){
    // true 代表 a 胜利, false 代表 b 胜利
    if(a == b) return 0;
    if(a == 0 && b == 2) return 1;
    if(a == 2 && b == 5) return 1;
    if(a == 5 && b == 0) return 1;
    return -1;
}


int main(){
    int N, Na, Nb;
    int a_list[100];
    int b_list[100];
    int a_i, b_i;
    int a_win, b_win;
    int state;
    while(scanf("%d %d %d", &N, &Na, &Nb) != EOF){
        a_i = 0; b_i = 0;
        a_win = 0; b_win = 0;
        for(int i = 0; i < Na; i++) scanf("%d", &a_list[i]);
        for(int i = 0; i < Nb; i++) scanf("%d", &b_list[i]);
        int i = 0;
        while(i < N){
            state = judge(a_list[a_i], b_list[b_i]);
            if(state == 1) a_win++;
            else if(state == -1) b_win++;
            a_i++; b_i++; i++;
            if(a_i == Na) a_i = 0;
            if(b_i == Nb) b_i = 0;
        }
        if(a_win == b_win){
            printf("draw\n");
        }else{
            if(a_win > b_win) printf("A\n");
            else printf("B\n");
        }
    }
    return 0;
}

