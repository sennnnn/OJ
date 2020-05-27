
// 类似的题，POJ 3984 POJ 2049
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

char matrix[40][40];

int flag[40][40];
int R,C;
int counts;

// recurrent method
bool ifpass(int x, int y){
    if(x < 0 || x >= R || y < 0 || y >= C) return 0;
    else if(flag[x][y] == 0) return 1;
    else return 0;
}

bool search_1(int x, int y){
    if(x == R-1 && y == C-1) return 1;
    if(ifpass(x-1, y)){
        flag[x-1][y] = 2;
        if(search_1(x-1, y)) {
            counts++;
            return 1;
        }else{
            flag[x-1][y] = 0;
        }
    }
    if(ifpass(x, y-1)){
        flag[x][y-1] = 2;
        if(search_1(x, y-1)) {
            counts++;
            return 1;
        }else{
            flag[x][y-1] = 0;
        }
    }
    if(ifpass(x+1, y)){
        flag[x+1][y] = 2;
        if(search_1(x+1, y)) {
            counts++;
            return 1;
        }else{
            flag[x+1][y] = 0;
        }
    }
    if(ifpass(x, y+1)){
        flag[x][y+1] = 2;
        if(search_1(x, y+1)) {
            counts++;
            return 1;
        }else{
            flag[x][y+1] = 0;
        }
    }
    return 0;
}

// date back method
typedef struct coord{
    int x;
    int y;
}coord;

bool ifpass(coord temp){
    int x = temp.x;
    int y = temp.y;
    if(x < 0 || x >= R || y < 0 || y >= C) return 0;
    else if(flag[x][y] == 0) return 1;
    else return 0;
}

int search_2(int x, int y){
    vector<coord> coord_list;
    coord temp;
    temp.x = x;temp.y = y;coord_list.push_back(temp);
    coord te;
    while(!coord_list.empty()){
        // printf("size: %d -- (%d, %d)\n", coord_list.size(), temp.x, temp.y);
        if(temp.x == R-1 && temp.y == C-1) break;
        
        // left
        te = temp;
        te.x -= 1;
        if(ifpass(te)){
            temp = te;
            flag[temp.x][temp.y] = 1;
            coord_list.push_back(temp);
            continue;
        }

        // right
        te = temp;
        te.x += 1;
        if(ifpass(te)){
            temp = te;
            flag[temp.x][temp.y] = 1;
            coord_list.push_back(temp);
            continue;
        }

        // down
        te = temp;
        te.y -= 1;
        if(ifpass(te)){
            temp = te;
            flag[temp.x][temp.y] = 1;
            coord_list.push_back(temp);
            continue;
        }

        // up
        te = temp;
        te.y += 1;
        if(ifpass(te)){
            temp = te;
            flag[temp.x][temp.y] = 1;
            coord_list.push_back(temp);
            continue;
        }

        temp = coord_list[coord_list.size()-1];
        coord_list.pop_back();
    }

    return coord_list.size();
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
        counts = 0;
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
        counts = search_2(0, 0);
        printf("%d\n", counts);
    }
}