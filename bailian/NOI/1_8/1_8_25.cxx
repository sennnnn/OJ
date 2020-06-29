/*
    题目名字: 螺旋加密
    题目编号: 2422
    日期: 2020 年 6 月 27 日
*/

#include <stdio.h>
#include <string.h>


void process(char temp, int *get){
    int num;
    if(temp == ' ') memset(get, 0, sizeof(int)*5);
    else if(temp >= 'A' && temp <= 'Z'){
        num = temp - 'A' + 1;
        for(int i = 4; i >= 0; i--){
            get[i] = num%2;
            num /= 2;
        }
    }
}

int main(){
    int storage[30][30], raw[900], get[6];
    char s[100];
    int R, C, len;
    int i, j, k, con; // i: 行下标; j: 列下标; k: 字符扫描长度
    int di[4] = {0, 1, 0, -1};
    int dj[4] = {1, 0, -1, 0};
    int RorC; // 表示当前循环是横向循环还是竖向循环, 横向循环为 j 变化, 竖向循环为 i 变化
    // process('C', get);
    // for(int i = 0; i < 5; i++){
    //     printf("%d", get[i]);
    // }
    // printf("\n");
    scanf("%d %d %[^\n]", &R, &C, s);
    memset(storage, 0, sizeof(storage)); memset(raw, 0, sizeof(raw));
    len = strlen(s); i = 0; j = 0; k = 0;
    // 先预处理
    for(i = 0; i < len; i++){
        process(s[i], get);
        for(j = 0; j < 5; j++){
            raw[k++] = get[j];
        }
    }
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            storage[i][j] = 2;
        }
    }
    i = 0; j = 0; k = 0; con = 0;
    while(k < R*C){
        if(storage[i][j] == 2){
            storage[i][j] = raw[k];
            k++;
        }else{
            if(storage[i+di[con]][j+dj[con]] != 2){
                con++; con %= 4;
                i += di[con];
                j += dj[con];
            }else{
                i += di[con];
                j += dj[con];
            }
        }
    }
    for(i = 0; i < R; i++){
        for(j = 0; j < C; j++){
            printf("%d", storage[i][j]);
        }
    }
    printf("\n");
}