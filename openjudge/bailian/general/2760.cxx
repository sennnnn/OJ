/*
    题目名字: 数字三角形
    编号: 1762
    日期: 2020 年 7 月 8 日
*/

#include <iostream>
#include <cstring>

using namespace std;

int N, max_val;
int state[110][250];
int dp[110][250];

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){
    cin >> N;
    memset(state, 0, sizeof(state));
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= i; j++){
            cin >> state[i][j];
        }
    }
    dp[1][1] = state[1][1];
    for(int i = 2; i <= N; i++){
        for(int j = 1; j <= i; j++){
            dp[i][j] = max(dp[i-1][j] + state[i][j], dp[i-1][j-1] + state[i][j]);
        }
    }
    max_val = -1;
    for(int i = 1; i <= N; i++){
        if(dp[N][i] > max_val) max_val = dp[N][i];
    }
    cout << max_val << endl;
}



/* DFS 做法 */
// #include <iostream>
// #include <cstring>

// using namespace std;

// int N, n, sum, max_val;
// int state[110][250];

// void dfs(int line, int col){
//     if(line == N){
//         sum += state[line][col];
//         if(sum > max_val) max_val = sum;
//         sum -= state[line][col];
//         return;
//     }
//     sum += state[line][col];
//     if(sum > max_val) max_val = sum;
//     dfs(line+1, col);
//     dfs(line+1, col+1);
//     sum -= state[line][col];
// }

// void visulization(){
//     int n = N;
//     for(int i = 1; i <= N; i++){
//         n--;
//         for(int j = 1; j <= n; j++){
//             cout << ' ';
//         }
//         int flag = 1;
//         for(int j = 1; j <= i;){
//             if(flag == 1) {cout << state[i][j]; flag = 0; j++;}
//             else {cout << ' '; flag = 1;}
//         }
//         cout << endl;
//     }
// }

// int main(){
//     cin >> N;
//     memset(state, 0, sizeof(state));
//     for(int i = 1; i <= N; i++){
//         for(int j = 1; j <= i; j++){
//             cin >> state[i][j];
//         }
//     }
//     sum = 0; max_val = -1;
//     dfs(1, 1);
//     cout << max_val << endl;
//     return 0;
// }