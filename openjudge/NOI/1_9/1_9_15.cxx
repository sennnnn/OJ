/*
    题目名字: 接水问题
    题目编号: 7917
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n, m, k, n_r, count, sum;
    int state[10010], get[10010];
    scanf("%d %d", &n ,&m);
    for(int i = 0; i < n; i++){
        scanf("%d", &state[i]);
    }
    for(int i = 0; i < m; i++){
        get[i] = state[i];
    }
    k = m;
    n_r = n-m;
    count = 0;
    sum = 1;
    while(n_r > 0 || sum > 0){
        sum = 0;
        for(int i = 0; i < m; i++){
            if(get[i] == 0 && k < n) {
                get[i] = state[k++];
                n_r--;
            }
            if(get[i] != 0) get[i]--;
            sum += get[i];
        }
        count++;
    }
    printf("%d\n", count);
    return 0;
}