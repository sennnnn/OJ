/*
    题目名字: 最大的矩形
    日期: 2020 年 7 月 14 日
*/

// 暴力解法
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int n;
    int state[1010];
    int max;
    memset(state, 0, sizeof(state));
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> state[i];
    }
    max = -1;
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int min = state[i];
            for(int k = i+1; k <= j; k++){
                if(min > state[k]) min = state[k];
            }
            if(min*(j-i+1) > max) max = min*(j-i+1); 
        }
    }
    cout << max << endl;
}