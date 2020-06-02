#include <stdio.h>

// HDU 2037

bool cmp(int a, int b){
    return a < b;
}

void sort_(int *a, int *b, int n){
    int temp;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(!cmp(a[j], a[j+1])){
                temp = a[j]; a[j] = a[j+1]; a[j+1] = temp;
                temp = b[j]; b[j] = b[j+1]; b[j+1] = temp;
            }
        }
    }
}


int calMaxProgram(int *start, int *end, int n){
    sort_(end, start, n);
    int count = 1;
    int last_start = start[0], last_end = end[0];
    // printf("++++++++++++++++++\n");
    // for(int i = 0; i < n; i++){
    //     printf("%d %d\n", start[i], end[i]);
    // }
    for(int i = 1; i < n; i++){
        if(start[i] >= last_end){
            // printf("%d\n", i);
            count++;
            last_start = start[i];
            last_end = end[i];
        }
    }
    return count;
}

int main(){
    int n;
    int start[100], end[100];
    int max_program;
    while(scanf("%d", &n) != EOF && n != 0){
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d %d", &start[i], &end[i]);
            getchar();
        }
        max_program = calMaxProgram(start, end, n);
        printf("%d\n", max_program);
    }
}