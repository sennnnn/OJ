#include <stdio.h>

int main(){
    int n;
    int key;
    int index = -1;
    int buf[200];
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d", &buf[i]);
        }
        getchar();
        scanf("%d", &key);
        for(int i = 0; i < n; i++){
            if(key == buf[i]){
                index = i; 
                break;
            }
        }
        printf("%d\n", index);
    }
}