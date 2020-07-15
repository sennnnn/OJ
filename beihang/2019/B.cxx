/*
    题目来源: http://www.noobdream.com/DreamJudge/Contest/45/1377/?Problem=B
    日期: 2020 年 7 月 15 日
*/

#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int state[12][12];
    int process[12][12];
    int k1, k2, k3, k4, n;
    while(cin >> n){
        memset(state, 0, sizeof(state));
        memset(process, 0, sizeof(process));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> state[i][j];
            }
        }

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                cin >> process[i][j];
            }
        }

        k1 = 0, k2 = 0, k3 = 0; k4 = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(state[i][j] == process[j][n+1-i]) k1++;
                if(state[i][j] == process[n+1-i][n+1-j]) k2++;
                if(state[i][j] == process[n+1-j][i]) k3++;
                if(state[i][j] == process[i][j]) k4++;
            }
        }
        if(k4 == n*n) cout << 0 << endl;
        else if(k1 == n*n) cout << 90 << endl;
        else if(k2 == n*n) cout << 180 << endl;
        else if(k3 == n*n) cout << 270 << endl;
        else cout << -1 << endl;
    }
}