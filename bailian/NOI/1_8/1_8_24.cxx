/*
    题目名字: 蛇形数组
    题目编号: 8184
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, i, j, k, round;
    int storage[20][20];
    int di[2] = {+1, -1};
    int dj[2] = {-1, +1};
    scanf("%d", &n);
    i = 0; j = 0; k = 1; round = 1;
    while(k <= n*n){
        storage[i][j] = k;
        k++;
        if(round && (i + di[round] == -1 || j + dj[round] == n)){
            if(j + dj[round] == n) i++;
            else if(i + di[round] == -1) j++;
            round = 0;
        }else if(round == 0 && (j + dj[round] == -1 || i + di[round] == n)){
            if(i + di[round] == n) j++;
            else if(j + dj[round] == -1) i++;
            round = 1;
        }else{
            i += di[round];
            j += dj[round];
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("%d ", storage[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}