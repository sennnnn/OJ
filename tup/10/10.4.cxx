/*
    题目名字: Help Jimmy
    编号: POJ 1661
*/

// 遍历写法
#include <stdio.h>
#include <string.h>
#include <stdlib.h> 

#define INFINITE 10000000

typedef struct panel{
    int Lx;
    int Rx;
    int h;
}panel;

int cmp(const void* a, const void* b){
    panel *p1, *p2;
    p1 = (panel *)a;
    p2 = (panel *)b;
    return p2->h - p1->h;
}

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int n;
int i, j;
int N, X, Y, MAX;
panel panels[1010];
int dp_l[1010];
int dp_r[1010];

int main(){
    scanf("%d", &n);
    for(int _ = 1; _ <= n; _++){
        scanf("%d %d %d %d", &N, &X, &Y, &MAX);
        for(int i = 1; i <= N; i++){
            scanf("%d %d %d", &panels[i].Lx, &panels[i].Rx, &panels[i].h);
        }
        panels[0].Lx = X;
        panels[0].Rx = X;
        panels[0].h = Y;
        qsort(panels, N+1, sizeof(panel), cmp);
        dp_l[N] = panels[N].h;
        dp_r[N] = panels[N].h;
        for(i = N-1; i >= 0; i--){
            int left_time, right_time;
            left_time = INFINITE;
            right_time = INFINITE;
            for(j = i+1; j <= N; j++){
                if(panels[j].Lx <= panels[i].Lx && panels[j].Rx >= panels[i].Lx) break;
            }
            left_time = min(left_time, panels[i].Lx - panels[j].Lx + panels[i].h - panels[j].h + dp_l[j]);
            left_time = min(left_time, panels[j].Rx - panels[i].Lx + panels[i].h - panels[j].h + dp_r[j]);
            if(j <= N){
                if(panels[i].h - panels[j].h > MAX){
                    left_time = INFINITE;
                }
            }else{
                if(panels[i].h > MAX){
                    left_time = INFINITE;
                }else{
                    left_time = panels[i].h;
                }
            }
            dp_l[i] = left_time;
            for(j = i+1; j <= N; j++){
                if(panels[j].Lx <= panels[i].Rx && panels[j].Rx >= panels[i].Rx) break;
            }
            right_time = min(right_time, panels[i].Rx - panels[j].Lx + panels[i].h - panels[j].h + dp_l[j]);
            right_time = min(right_time, panels[j].Rx - panels[i].Rx + panels[i].h - panels[j].h + dp_r[j]);
            if(j <= N){
                if(panels[i].h - panels[j].h > MAX){
                    right_time = INFINITE;
                }
            }else{
                if(panels[i].h > MAX){
                    right_time = INFINITE;
                }else{
                    right_time = panels[i].h;
                }
            }
            dp_r[i] = right_time;
        }
        printf("%d\n", min(dp_l[0], dp_r[0]));
    }
}

// 递归写法
// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>

// #define INFINITE 1000000

// typedef struct panel{
//     int Lx;
//     int Rx;
//     int h;
// }panel;

// int cmp(const void* a, const void* b){
//     panel *p1, *p2;
//     p1 = (panel *)a;
//     p2 = (panel *)b;
//     return p2->h - p1->h;
// }

// int min(int a, int b){
//     if(a < b) return a;
//     else return b;
// }

// int n;
// int N, X, Y, MAX;
// panel panels[1010];
// int dp_l[1010];
// int dp_r[1010];

// int MinTime(int index, bool ifleft){
//     int i, x;
//     int y = panels[index].h;
//     if(ifleft){
//         x = panels[index].Lx;
//     }else{
//         x = panels[index].Rx;
//     }

//     for(i = index+1; i <= N; i++){
//         if(panels[i].Lx <= x && panels[i].Rx >= x) break;
//     }

//     if(i <= N){
//         if(y - panels[i].h > MAX) {
//             return INFINITE;
//         }
//     }else{
//         if(y > MAX) {
//             return INFINITE;
//         }
//         else return y;
//     }
//     int moveLeftTime = x - panels[i].Lx + y - panels[i].h;
//     int moveRightTime = panels[i].Rx - x + y - panels[i].h;
//     if(dp_l[i] == -1) dp_l[i] = MinTime(i, 1);
//     if(dp_r[i] == -1) dp_r[i] = MinTime(i, 0);
//     moveLeftTime += dp_l[i];
//     moveRightTime += dp_r[i];
//     if(moveLeftTime < moveRightTime) return moveLeftTime;
//     else return moveRightTime;
// }

// int main(){
//     scanf("%d", &n);
//     for(int _ = 0; _ < n; _++){
//         scanf("%d %d %d %d", &N, &X, &Y, &MAX);
//         memset(dp_l, -1, sizeof(dp_l));
//         memset(dp_r, -1, sizeof(dp_r));
//         for(int i = 1; i <= N; i++){
//             scanf("%d %d %d", &panels[i].Lx, &panels[i].Rx, &panels[i].h);
//         }
//         panels[0].Lx = X;
//         panels[0].Rx = X;
//         panels[0].h = Y;
//         qsort(panels, N+1, sizeof(panel), cmp);
//         printf("%d\n", MinTime(0, 1));
//     } 
// }