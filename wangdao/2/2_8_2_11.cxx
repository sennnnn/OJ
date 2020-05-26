#include <stdio.h>
#include <stdlib.h>

char storage[80][80];

int main(){
    int n;
    char in, out;
    while(scanf("%d %c %c", &n, &in, &out) == 3){
        int x, y;
        int r_x, r_y;
        char char_;
        x = y = (n-1)/2;
        r_x = r_y = (n-1)/2;
        for(int index = 0; index <= (n-1)/2; index++){
            char_ = index % 2 == 0 ? in : out;
            for(int i = x; i <= r_x; i++){
                storage[i][y] = char_;
                storage[i][r_y] = char_;
            }
            for(int j = y+1; j <= r_y-1; j++){
                storage[x][j] = char_;
                storage[r_x][j] = char_;
            }
            x = x - 1; y = y - 1;
            r_x = r_x + 1; r_y = r_y + 1;
        }
        storage[0][0] = ' '; storage[0][1] = ' ';
        storage[n-1][0] = ' '; storage[n-1][1] = ' ';
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                printf("%c", storage[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}