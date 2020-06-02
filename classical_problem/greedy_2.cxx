#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a > b;
}

// hdu 2124 Accepted 0Ms

int main(){
    int L, N;
    int blocks[600];
    int count;
    while(scanf("%d %d", &L, &N) != EOF){
        for(int i = 0; i < N; i++){
            scanf("%d", &blocks[i]);
        }
        sort(blocks, blocks+N, cmp);
        count = 0;
        for(int i = 0; i < N; i++){
            count++;
            L -= blocks[i];
            if(L <= 0) break;
        }
        if(L > 0) printf("impossible\n");
        else printf("%d\n", count);
    }
}