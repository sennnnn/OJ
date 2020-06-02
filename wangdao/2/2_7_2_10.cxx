#include <stdio.h>


int main(){
    int h;
    int bottom_w;
    int top_w;
    while(scanf("%d", &h) != EOF){
        top_w = h;
        bottom_w = h + (h-1)*2;
        for(int i = 0; i < h; i++){
            for(int j = 0; j < bottom_w; j++){
                if(j < bottom_w - (top_w + 2*i)) printf(" ");
                else printf("*");
            }
            printf("\n");
        }
    }
    return 0;
}