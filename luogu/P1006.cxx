/*
    题目名字: 传纸条
    备注: 动态规划, 费用流, NOIP 提高组, 四维 dp 转三维 dp 的方法: https://www.luogu.com.cn/problem/solution/P1006
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
    int state[51][51], dp[101][51][51];
    int i, j, k, m, n;
    scanf("%d %d", &m, &n);
    memset(state, 0, sizeof(state)); memset(dp, 0, sizeof(dp));
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &state[i][j]);
        }
    }
    for(k = 2; k <= m+n; k++){
        for(i = 1; i <= m; i++){
            for(j = i+1; j <= m; j++){
                if(k - i < 1 || k - j < 1) continue;
                dp[k][i][j] = max(dp[k-1][i-1][j], dp[k-1][i][j-1], dp[k-1][i-1][j-1], dp[k-1][i][j]);
                dp[k][i][j] += state[i][k-i] + state[j][k-j];
            }
        }
    }
    printf("%d\n", dp[m+n-1][m-1][m]);
}















// 四维 DP 过不了
#include <stdio.h>
#include <string.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    int m, n, i, j, k, l, mx;
    printf("1");
    int state[51][51], dp[51][51][51][51];
    scanf("%d %d", &m, &n);
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &state[i][j]);
        }
    }
    memset(state, 0, sizeof(state)); 
    memset(dp, 0, sizeof(dp));
    for(i = 1; i <= m; i++){
        for(j = 1; j <= n; j++){
            for(k = i; k <= m; i++){
                for(l = j; j <= n; j++){
                    mx = -1;
                    mx = max(dp[i-1][j][k-1][l], mx);
                    mx = max(dp[i-1][j][k][l-1], mx);
                    mx = max(dp[i][j-1][k-1][l], mx);
                    mx = max(dp[i][j-1][k][l-1], mx);
                    dp[i][j][k][l] = mx;
                }
            }
        }
    }
    printf("%d\n", dp[m][n][m][n]);
}