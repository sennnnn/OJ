/*
    !! 未解决，需要用二维 dp
    题目名字: 大教室中传纸条
    备注: 动态规划, 费用流, https://www.luogu.com.cn/problem/solution/P1006
    日期: 2020 年 7 月 3 日
*/

#include <stdio.h>
#include <string.h>

int max(int a, int b, int c, int d){
    if(b > a) a = b;
    if(c > a) a = c;
    if(d > a) a = d;
    return a;
}

int main(){
    int m, n, i, j, k;
    int state[201][201], dp[401][201][201];
    scanf("%d %d", &m, &n);
    memset(state, 0, sizeof(state)); memset(dp, 0, sizeof(dp));
    for(i = 1; i < m; i++){
        for(j = 1; j < n; j++){
            scanf("%d", &state[i][j]);
        }
    }
    for(k = 3; k <= m+n-1; k++){
        for(i = 1; i <= m; i++){
            for(j = i+1; j <= m; j++){
                if(k-i < 1 || k-j < 1) continue;
                dp[k][i][j] = max(dp[k-1][i-1][j], dp[k-1][i][j-1], dp[k-1][i][j], dp[k-1][i-1][j-1]);
                dp[k][i][j] += state[i][k-i] + state[j][k-j];
            }
        }
    }
    printf("%d\n", dp[m+n-1][m-1][m]);
}