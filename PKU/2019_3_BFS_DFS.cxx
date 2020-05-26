
// 类似的题，POJ 3984 POJ 2049
#include <stdio.h>
#include <string.h>

char matrix[40][40];

int flag[40][40];
int R,C;
int count;

bool ifpass(int x, int y){
    if(x < 0 || x >= R || y < 0 || y >= C) return 0;
    else if(flag[x][y] == 0) return 1;
    else return 0;
}

bool search(int x, int y){
    if(x == R-1 && y == C-1) return 1;
    if(ifpass(x-1, y)){
        flag[x-1][y] = 2;
        if(search(x-1, y)) {
            count++;
            return 1;
        }else{
            flag[x-1][y] = 0;
        }
    }
    if(ifpass(x, y-1)){
        flag[x][y-1] = 2;
        if(search(x, y-1)) {
            count++;
            return 1;
        }else{
            flag[x][y-1] = 0;
        }
    }
    if(ifpass(x+1, y)){
        flag[x+1][y] = 2;
        if(search(x+1, y)) {
            count++;
            return 1;
        }else{
            flag[x+1][y] = 0;
        }
    }
    if(ifpass(x, y+1)){
        flag[x][y+1] = 2;
        if(search(x, y+1)) {
            count++;
            return 1;
        }else{
            flag[x][y+1] = 0;
        }
    }
    return 0;
}

void print_matrix(char (*src)[40], int R, int C){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%c", src[i][j]);
        }
        printf("\n");
    }
}

void print_matrix(int (*src)[40], int R, int C){
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            printf("%d", src[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int x,y;
    int nx,ny;
    while(scanf("%d %d", &R, &C) != EOF){
        x = 0;y = 0;
        count = 0;
        memset(flag, 0, sizeof(int)*40*40);
        getchar();
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                scanf("%c", &matrix[i][j]);
                if(matrix[i][j] == '.') flag[i][j] = 0;
                else flag[i][j] = 1;
            }
            getchar();
        }
        search(0, 0);
        count++;
        printf("%d", count);
    }
}