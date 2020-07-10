/*
    题目名字: 木材切割
    编号: 20064
    日期: 2020 年 7 月 10 日
*/

#include <iostream>
#include <cstring>

using namespace std;

int state[110];
int dp[110][110];
int N, M;

int max(int a, int b){
    if(a > b) return a;
    else return b;
}

int main(){

    memset(state, 0, sizeof(state));
    memset(dp, 0, sizeof(dp));
    cin >> N >> M;
    for(int i = 1; i <= N; i++){
        cin >> state[i];
        dp[i][1] = state[i];
    }
    for(int i = 2; i <= M; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= j; k++){
                dp[j][i] = max(dp[j][i], state[k] + dp[j - k][i-1]);
            }
        }
    }
    cout << dp[N][M] << endl;
}














/* dfs */

// #include <iostream>
// #include <cstring>

// using namespace std;

// int N, M, max_val, sum;
// int state[110];

// void dfs(int n, int m){
//     if(m == 0){
//         if(sum > max_val){
//             max_val = sum;
//         }
//         return;
//     }
//     for(int i = 1; i <= n; i++){
//         sum += state[i];
//         dfs(n-i, m-1);
//         sum -= state[i];
//     }
// }

// int main(){
//     memset(state, 0, sizeof(state));
//     cin >> N >> M;
//     for(int i = 1; i <= N; i++){
//         cin >> state[i];
//     }
//     max_val = 0; sum = 0;
//     dfs(N, M);
//     cout << max_val << endl;
// }