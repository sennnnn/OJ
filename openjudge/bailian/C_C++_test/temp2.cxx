#include <stdio.h>
#include <string.h>

int main(){
    int n, k, i, j;
    int state[12][12];
    scanf("%d %d", &n, &k);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &state[i][j]);
        }
    }
    int max_i = 1; int count_dis; int search_i;
    for(i = 2; i <= n; i++){
        if(state[1][i] <= k){
            count_dis = 0;
            search_i = 1;
            j = i;
            while(1){
                count_dis += state[search_i][j];
                if(count_dis <= k){
                    if(j > max_i) max_i = j;
                    search_i++; j++;
                }else break;
            }
        }
    }
    printf("%d\n", max_i);
}