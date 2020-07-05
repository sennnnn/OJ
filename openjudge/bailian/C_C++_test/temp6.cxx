/*
    题目名字: 木材切割
    题目编号: 20064
    日期: 2020 年 7 月 4 日
    备注: 动态规划
*/

#include <stdio.h>
#include <string.h>

int n, m, i, j;
int value[110], sum[110][110];

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int dp(int n, int m){
    if(m == 0) return sum[n][m];
    for(i = 1; i <= n; i++){
        if(n - i >= 0) sum[n][m] = max(sum[n][m], value[i] + dp(n-i, m-1));
    }
    return sum[n][m];
}

int main(){
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        scanf("%d", &value[i]);
        sum[i][0] = value[i];
    }
    printf("%d\n", dp(n, m));
}




// 错误
// #include <stdio.h>
// #include <string.h>

// typedef struct wood{
//     int len;
//     int value;
//     double value_rate;
// }wood;

// void _sort(wood _list[], int len){
//     for(int i = 1; i <= len; i++){
//         for(int j = i+1; j <= len; j++){
//             if(_list[j].value_rate > _list[i].value_rate){
//                 wood temp;
//                 temp = _list[i];
//                 _list[i] = _list[j];
//                 _list[j] = temp;
//             }
//         }
//     }
// }

// int main(){
//     int n, m, i, j;
//     int len, value, max;
//     wood woods[110];
//     scanf("%d %d", &n, &m);
//     for(i = 1; i <= n; i++){
//         scanf("%d", &woods[i].value);
//         woods[i].len = i;
//         woods[i].value_rate = (double)woods[i].value/i;
//     }
//     _sort(woods, n);
//     max = -1;
//     for(int count = 1; count <= n; count++){
//         len = 0;
//         value = 0;
//         j = count;
//         printf("wood segmentation way: ");
//         for(i = 1; i <= m;){
//             if(len + woods[j].len <= n){
//                 i++;
//                 value += woods[j].value;
//                 len += woods[j].len;
//                 printf("%d ", woods[j].len);
//             }else{
//                 j++;
//             }
//             if(j == n+1) break;
//         }
//         printf("\n");
//         if(i == m+1){
//             if(value > max){
//                 max = value;
//             }
//         }
//         printf("value and count: %d %d\n", value, i);
//     }
//     printf("%d\n", max);
        
// }