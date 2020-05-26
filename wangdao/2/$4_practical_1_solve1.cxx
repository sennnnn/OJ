/**************************************************
 * 普通解法 *
***************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

char storage[3000][3000];

char temp[5][5];

void copy(char (*src)[3000], char(*dst)[3000], int x, int y, int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dst[x + i][y + j] = src[i][j];
        }
    } 
}

void setTemp(char (*src)[3000], char (*temp)[5], int x, int y, int n){
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            src[i][j] = temp[i][j];
        }
    }
}

void setSpace(char (*src)[3000], int x, int y, int n){
    for(int i = x; i < x+n; i++){
        for(int j = y; j < y+n; j++){
            src[i][j] = ' ';
        }
    }
}

void print_matrix(char (*src)[3000], int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%c", src[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int n,m;
    int n_temp;
    memset(storage, 0, sizeof(char)*3000*3000);
    memset(temp, 0, sizeof(char)*5*5);

    while(scanf("%d", &n) != EOF && n != 0){
        getchar();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = getchar();
            }
            getchar();
        }
        n_temp = n;
        scanf("%d", &m);
        if(m == 1){
            setTemp(storage, temp, 0, 0, n);
            print_matrix(storage, n_temp);
        }else{
            setTemp(storage, temp, 0, 0, n);
            for(int r = 1; r < m; r++){
                for(int i = 0; i < n; i++){
                    for(int j = 0; j < n; j++){
                        if(i == 0 && j == 0) continue;
                        if(temp[i][j] == ' ') {
                            setSpace(storage, i*n_temp, j*n_temp, n_temp);
                        }else{
                            copy(storage, storage, i*n_temp, j*n_temp, n_temp);
                        }
                    }
                }
                if(temp[0][0] == ' ') setSpace(storage, 0, 0, n_temp);
                n_temp = (int)pow((double)n, (double)(r+1));
            }
            print_matrix(storage, n_temp);
        }     
    }
    return 0;
}