/*
    题目名字: 小白鼠排队
    编号: 1945
    日期: 2020 年 7 月 7 日
*/

#include <stdio.h>
#include <string.h>

typedef struct mouse{
    int weight;
    char color[100];
}mouse;


void sort_(mouse mouses[], int len){
    for(int i = 0; i < len; i++){
        for(int j = i+1; j < len; j++){
            if(mouses[j].weight > mouses[i].weight){
                mouse temp;
                temp = mouses[i];
                mouses[i] = mouses[j];
                mouses[j] = temp;
            }
        }
    }
}


int main(){
    mouse mouses[1010];
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        scanf("%d %s", &mouses[i].weight, mouses[i].color);
    }
    sort_(mouses, N);
    for(int i = 0; i < N; i++){
        printf("%s\n", mouses[i].color);
    }
}