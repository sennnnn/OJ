#include <stdio.h>
#include <string.h>

int count[1000001];

int *hash(int *count, int key){
    int temp = key + 500000;
    return &count[temp];
}

int main(){
    memset(count, 0, sizeof(int)*1000001);
    int n,n_;
    int temp;
    int *temp_pointer;
    int output_count = 0;
    while(scanf("%d %d", &n, &n_) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &temp);
            temp_pointer = hash(count, temp);
            *temp_pointer += 1;
        }
        output_count = 0;
        for(int i = 1000000; i >= 0; i--){
            if(count[i] != 0) {
                printf("%d ", i - 500000);
                output_count++;
            }
            if(output_count == n_) break;
        }
        printf("\n");
    }
    return 0;
}
