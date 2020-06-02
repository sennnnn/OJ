#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int hash[201];

int main(){
    memset(hash, 0, sizeof(int)*201);
    int n,m;
    int temp;
    int *keys;
    while(scanf("%d %d", &n, &m) != EOF){
        keys = (int *)malloc(sizeof(int)*n);
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            hash[temp] += 1;
            keys[i] = temp;
        }
        for(int i = 0; i < n; i++){
            if(hash[keys[i]] == 1) printf("BeiJu\n");
            else printf("%d\n", hash[keys[i]] - 1);
        }
        free(keys);
    }
    return 0;
}