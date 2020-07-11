#include <stdio.h>
#include <string.h>

int main(){
    int N;
    int state[1010];
    int dp[1010];
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) {
        scanf("%d", &state[i]);
    }
    dp[1] = 1;
    for(int i = 2; i <= N; i++) {
        int tmp = 0;
        for(int j = 1; j <= i; j++){
            if(state[i] > state[j]){
                if(dp[j] > tmp)
                    tmp = dp[j];
            }
        }
        dp[i] = tmp+1;
    }
    int max = -1;
    for(int i = 1; i <= N; i++){
        if(max < dp[i]) max = dp[i];
    }
    printf("%d\n", max);
}