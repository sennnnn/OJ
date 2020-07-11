/*
    题目名字: Common Subsequence
    编号: POJ 1458
*/

#include <stdio.h>
#include <string.h>

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    char s1[210], s2[210];
    int dp[210][210];
    int n1, n2;
    while(scanf("%s %s", s1, s2) != EOF){
        n1 = strlen(s1);
        n2 = strlen(s2);
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n1; i++){
            for(int j = 1; j <= n2; j++){
                if(s1[i-1] == s2[j-1]) 
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        printf("%d\n", dp[n1][n2]);
    }
}