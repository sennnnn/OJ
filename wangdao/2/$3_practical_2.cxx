#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int count[10001];

int main(){
    int l,m;
    int low,high;
    int sum = 0;
    memset(count, 0, sizeof(int)*10001);
    while(scanf("%d %d", &l, &m) != EOF){
        for(int i = 0; i <= l; i++){
            count[i] = 1;
        }
        for(int i = 0; i < m; i++){
            scanf("%d %d", &low, &high);
            for(int j = low; j <= high; j++){
                count[j] = count[j] == 1 ? 0 : 0;
            }
        }
        for(int i = 0; i <= l; i++){
            sum += count[i];
        }
        printf("%d\n", sum);
    }
    return 0;
}