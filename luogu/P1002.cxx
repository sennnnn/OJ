/*
    题目名字: 过河卒
    备注: 动态规划
    日期: 2020 年 7 月 3 日
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n, m, x, y, i, j;
    int state[30][30];
    double dp[30][30];

    memset(state, 0, sizeof(state)); memset(dp, 0, sizeof(dp));
    scanf("%d %d %d %d", &m, &n, &x, &y);
    
    x += 1; y += 1;
    state[x][y] = 1; 

    if(x-1 >= 1   && y+2 <= n+1) state[x-1][y+2] = 1; 
    if(x+1 <= m+1 && y+2 <= n+1) state[x+1][y+2] = 1;
    if(x-1 >= 1   && y-2 >= 1)   state[x-1][y-2] = 1; 
    if(x+1 <= m+1 && y-2 >= 1)   state[x+1][y-2] = 1;
    if(x+2 <= m+1 && y-1 >= 1)   state[x+2][y-1] = 1; 
    if(x-2 >= 1   && y-1 >= 1)   state[x-2][y-1] = 1;
    if(x+2 <= m+1 && y+1 <= n+1) state[x+2][y+1] = 1; 
    if(x-2 >= 1   && y+1 <= n+1) state[x-2][y+1] = 1;
    
    if(state[2][1] != 1) dp[2][1] = 1; 
    if(state[1][2] != 1) dp[1][2] = 1;

    for(i = 1; i <= m+1; i++){
        for(j = 1; j <= n+1; j++){
            dp[i][j] += dp[i][j-1] + dp[i-1][j];
            if(state[i][j] == 1) dp[i][j] = 0;
        }
    }
    // for(i = 1; i <= m+1; i++){
    //     for(j = 1; j <= n+1; j++){
    //         printf("%.0lf ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    if(state[1][1] == 1) printf("0\n");
    else printf("%.0lf\n", dp[m+1][n+1]);
}