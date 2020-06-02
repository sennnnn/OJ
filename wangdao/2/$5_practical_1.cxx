#include <stdio.h>


int main(){
    int k;
    int elements[80];
    while(scanf("%d", &k) != EOF){
        getchar();
        for(int i = 0; i < k; i++){
            scanf("%d", &elements[i]);
        }

        for(int i = 0; i < k; i++){
            if(i == 0){
                if(elements[i] != elements[i+1])
                    printf("%d ", i);
            }else if(i == k-1){
                if(elements[i] != elements[i-1])
                    printf("%d ", i);
            }else{
                if(elements[i] > elements[i-1] && elements[i] > elements[i+1]){
                    printf("%d ", i);
                }else if(elements[i] < elements[i-1] && elements[i] < elements[i+1]){
                    printf("%d ", i);
                }
            }
        }
        printf("\n");
    }
    return 0;
}