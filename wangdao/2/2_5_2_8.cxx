#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int count[101];

int main(){
    int n;
    int designated;
    int temp;
    memset(count, 0, sizeof(int)*101);
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            count[temp] += 1;
        }
        scanf("%d", &designated);
        printf("%d\n", count[designated]);
    }
    return 0;
}