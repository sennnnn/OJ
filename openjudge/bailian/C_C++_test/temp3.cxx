/*
    题目名字: 硬币问题
    题目编号: 20063
    日期: 2020 年 7 月 4 日
*/

#include <stdio.h>
#include <string.h>

typedef struct coin{
    int weight;
    int value;
    double wv_rate;
}coin;

void sort_(coin coin_list[], int len){
    coin temp;
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(coin_list[i].wv_rate < coin_list[j].wv_rate){
                temp = coin_list[i];
                coin_list[i] = coin_list[j];
                coin_list[j] = temp;
            }
        }
    }
}

int main(){
    int N, C;
    int weight_count, value_count, select_i;
    coin coin_list[110];
    scanf("%d %d", &N, &C);
    for(int i = 0; i < N; i++){
        scanf("%d", &coin_list[i].weight);
    }
    for(int i = 0; i < N; i++){
        scanf("%d", &coin_list[i].value);
    }
    for(int i = 0; i < N; i++){
        coin_list[i].wv_rate = (double)coin_list[i].value/coin_list[i].weight;
    }
    sort_(coin_list, N);
    weight_count = 0;
    value_count = 0;
    select_i = 0;
    while(1){
        if(weight_count + coin_list[select_i].weight <= C){
            weight_count += coin_list[select_i].weight;
            value_count += coin_list[select_i].value;
        }else{
            select_i++;
        }
        if(select_i == N) break;
    }
    printf("%d\n", value_count);
    return 0;
}