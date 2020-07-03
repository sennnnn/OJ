/*
    题目名字: 方格取数
    备注: 动态规划, 递归, NOIP 提高组
    日期: 2020 年 7 月 3 日
*/

#include <stdio.h>
#include <string.h>
#include <math.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int N, i, j, k, l, v;
    int state[12][12], dp[12][12][12][12];
    
    scanf("%d", &N);
    memset(state, 0, sizeof(state));
    memset(dp, 0, sizeof(dp));
    while(1){
        scanf("%d %d %d", &i, &j, &v);
        state[i][j] = v;
        if(i == 0 && j == 0 && v == 0) break;
    }

    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            for(k = 1; k <= N; k++){
                l = i + j - k;
                if(l < 1) break;
                dp[i][j][k][l] = max(dp[i][j-1][k][l-1], max(dp[i-1][j][k][l-1], max(dp[i-1][j][k-1][l], dp[i][j-1][k-1][l])));
                if(i == k && j == l) dp[i][j][k][l] += state[i][j];
                else dp[i][j][k][l] += state[i][j] + state[k][l];
            }
        }
    }
    printf("%d\n", dp[N][N][N][N]);
    return 0;
}