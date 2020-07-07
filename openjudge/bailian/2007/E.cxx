/*
    题目名字: 神奇的口袋
    编号: 1757
    日期: 2020 年 7 月 8 日
*/

#include <iostream>
#include <cstring>

using namespace std;

typedef struct thing{
    int volume;
    int flag = 0;
}thing;

int n;
int ct;
thing things[30];
int flag[30];

void dfs(int index){
    if(index == n){
        int volume = 0;
        for(int i = 1; i <= n; i++){
            if(flag[i] == 1) volume += things[i].volume;
        }
        if(volume == 40) ct++;
        return;
    }
    int volume = 0;
    for(int i = 1; i <= n; i++){
        if(flag[i] == 1) volume += things[i].volume;
    }
    if(volume == 40) ct++;
    for(int i = index+1; i <= n; i++){
        flag[i] = 1;
        dfs(i);
        flag[i] = 0;
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> things[i].volume;
    }
    memset(flag, 0, sizeof(flag));
    ct = 0;
    for(int i = 1; i <= n; i++){
        flag[i] = 1;
        dfs(i);
        flag[i] = 0;
    }
    cout << ct << endl;
}