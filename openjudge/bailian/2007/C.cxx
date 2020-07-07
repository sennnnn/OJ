/*
    题目名字: 拦截导弹
    编号: 1947
    日期: 2020 年 7 月 7 日
*/

#include <iostream>
#include <cstring>

using namespace std;

int k, ct;
int state[26];
int flag[26];

void dfs(int index){
    if(index == k){
        flag[index] = 1;
        int c = 0;
        for(int i = 1; i <= k; i++){
            if(flag[i] == 1) c++;
        }
        if(c > ct){
            ct = c;
        }
        flag[index] = 0;
        return;
    }
    int ifmin = 1;
    for(int i = index + 1; i <= k; i++){
        if(state[i] <= state[index]){
            flag[i] = 1;
            dfs(i);
            flag[i] = 0;
            ifmin = 0;
        }
    }
    if(ifmin){
        int c = 0;
        for(int i = 1; i <= k; i++){
            if(flag[i] == 1) c++;
        }
        if(c > ct){
            ct = c;
        }
    }
}

int main(){
    memset(flag, 0, sizeof(flag)); memset(state, 0, sizeof(state));
    ct = 0;
    cin >> k;
    for(int i = 1; i <= k; i++){
        cin >> state[i];
    }
    for(int i = 1; i <= k; i++){
        flag[i] = 1;
        dfs(i);
        flag[i] = 0;
    }
    cout << ct << endl;
}