/*
    题目名字: 最短路
    题目编号: 19895
    日期: 2020 年 7 月 4 日
    备注: DFS
*/

#include <stdio.h>
#include <string.h>

int min = 99999999;
int n, k, i, j;
int state[12][12];
int path[12] = {0};
int min_path[12] = {0};

void dfs(int index, int sum){

    if(index == n){
        if(sum < min){
            min = sum;
            memset(min_path, 0, sizeof(min_path));
            int j = 1;
            for(int i = 1; i <= n; i++){
                if(path[i] == 1){
                    min_path[j++] = i;
                }
            }
        }
        return;
    }

    for(int i = index+1; i <= n; i++){
        path[i] = 1;
        dfs(i, sum+state[index][i]);
        path[i] = 0;
    }
}

int main(){
    scanf("%d", &n);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            scanf("%d", &state[i][j]);
        }
    }
    path[1] = 1;
    dfs(1, 0);
    printf("%d\n", min);
    for(int i = 1; ;i++){
        printf("%d ", min_path[i]);
        if(min_path[i] == n) {
            printf("\n");
            break;
        }
    }
    return 0;
}