#include <stdio.h>
#include <string.h>

int state[110][110];
int dp[110][110];
int N;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int dfs(int line, int col){
    if(line == N){
        return state[line][col];
    }
    if(dp[line+1][col] == -1)
        dp[line+1][col] = dfs(line+1, col);
    if(dp[line+1][col+1] == -1)
        dp[line+1][col+1] = dfs(line+1, col+1);
    return max(dp[line+1][col]+state[line][col], dp[line+1][col+1]+state[line][col]);
}

int main(){
    memset(state, 0, sizeof(state));
    memset(dp, -1, sizeof(dp));
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            scanf("%d", &state[i][j]);
        }
    }
    printf("%d\n", dfs(1, 1));
}