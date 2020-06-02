
/****************************
 * 递归解法 *
*****************************/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>

using namespace std;

char map[3002][3002];
char temp[6][6];

int n;

void dfs(int m, int x, int y){
    if(m == 1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                map[x + i][y + j] = temp[i][j];
            }
        }
        return;
    }
    else{
        int size = (int)pow(n*1.0, m - 1);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++){
                if(temp[i][j] != ' ') dfs(m - 1, x + i*size, y + j*size);
            }
    }
}

int main(){
    int m,size;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                temp[i][j] = getchar();
            }
            getchar();
        }
        scanf("%d", &m);
        printf("%d", m);
        size = (int)pow(n*1.0, m);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                map[i][j] = ' ';
            }
        }
        dfs(m, 0, 0);
        for(int i = 0; i < size; i++){
            for(int j = 0; j < size; j++){
                printf("%c", map[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}