/*
    题目名字: 矩阵取数的游戏
    备注: 动态规划, NOIP 提高组, 区间 dp
    日期: 2020 年 7 月 3 日
*/

// 区间 dp
#include <stdio.h>
#include <string.h>

int get[82][82];
int state[82][82];
int n, m;
int i, j, l, sum;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int pow(int n, int value){
    int base = value;
    for(int i = 1; i < n; i++){
        value *= base;
    }
    return value;
}

int dp(int L, int R){
    if(R-L >= 1) get[L][R] = max(dp(L+1, R) + state[l][L]*pow(m-(R-L), 2), dp(L, R-1) + state[l][R]*pow(m-(R-L), 2));
    else get[L][R] = state[l][L]*pow(m-(R-L), 2);
    return get[L][R];
}

int main(){
    scanf("%d %d", &n, &m);
    memset(state, 0, sizeof(state)); memset(get, 0, sizeof(get));
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            scanf("%d", &state[i][j]);
        }
    }
    sum = 0;
    for(l = 1; l <= n; l++){
        memset(get, 0, sizeof(get));
        sum += dp(1, m);
    }
    printf("%d\n", sum);

}


// 普通 dp
// #include <stdio.h>
// #include <string.h>

// int pow(int n, int value){
//     int base = value;
//     for(int i = 1; i < n; i++){
//         value *= base;
//     }
//     return value;
// }

// // typedef struct HP{
// //     int num[81];
// // }HP;

// // bool compare(HP a, HP b){
// //     for(int i = 1; i <= 1010; i++){
// //         if(a.num[i] < b.num[i]) return 0;
// //     }
// //     return 1;
// // }

// // HP max(HP a, HP b){
// //     for(int i = 1; i <= 1010; i++){
// //         if(a.num[i] < b.num[i]) return b;
// //     }
// //     return a;
// // }

// // HP max(HP a, HP b, int add_a, int add_b, int index){
// //     a.num[index] += add_a;
// //     a.num[index] += add_b;
// //     for(int i = 1010; i >= 1; i--){
// //         if(a.num[i] < b.num[i]) return b;
// //     }
// //     return a;
// // }

// // HP add(HP a, HP b){
// //     for(int i = 1010; i >= 1; i--){
// //         a.num[i] += b.num[i];
// //     }
// //     return a;
// // }

// int max(int a, int b){
//     if(a > b) return a;
//     else return b;
// }

// int main(){
//     int sum, max_HP;
//     int dp[82][82];
//     int state[82][82];
//     int n, m, i, j, l, round;
//     memset(state, 0, sizeof(state));
//     scanf("%d %d", &n, &m);
//     for(i = 1; i <= n; i++){
//         for(j = 1; j <= m; j++){
//             scanf("%d", &state[i][j]);
//         }
//     }
    
//     for(l = 1; l <= n; l++){
//         memset(dp, 0, sizeof(dp));
//         for(i = 1; i <= m; i++){
//             for(j = m; j >= 1; j--){
//                 dp[i][j] = max(dp[i][j], dp[i-1][j] + state[l][i-1]*pow(m - j + i - 1, 2));
//                 dp[i][j] = max(dp[i][j], dp[i][j+1] + state[l][j+1]*pow(m - j + i - 1, 2));
//             }
//         }
//         int temp = 0;
//         for(i = 1; i <= m; i++){
//             temp = max(dp[i][i] + state[l][i]*pow(m, 2), temp);
//         }
//         printf("%d\n", temp);
//         sum += temp;
//     }   
// }