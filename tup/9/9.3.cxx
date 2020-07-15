#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int flag[10];
int state[10][10];
vector<int> temp;
vector<vector<int>> res;

bool judge(vector<int> temp){
    if(temp.size() != 8) return false;
    memset(state, 0, sizeof(state));
    for(int i = 0; i < temp.size(); i++){
        state[i+1][temp[i]] = 1;
    }
    int flag = 1;
    int x, y;
    for(int i = 0; i < 8; i++){
        x = i + 1;
        y = temp[i];
        while(1){
            x--; y--;
            if(x == 0 || y == 0) break;
            if(state[x][y] == 1) flag = 0;
        }
        x = i + 1;
        y = temp[i];
        while(1){
            x++; y++;
            if(x == 9 || y == 9) break;
            if(state[x][y] == 1) flag = 0;
        }
        x = i + 1;
        y = temp[i];
        while(1){
            x++; y--;
            if(x == 9 || y == 0) break;
            if(state[x][y] == 1) flag = 0;
        }
        x = i + 1;
        y = temp[i];
        while(1){
            x--; y++;
            if(x == 0 || y == 9) break;
            if(state[x][y] == 1) flag = 0;
        }
    }
    if(flag) return true;
    else return false;
}

void queen(){
    if(temp.size() == 8){
        if(judge(temp)) res.push_back(temp);
        return ;
    }
    for(int i = 1; i <= 8; i++){
        if(flag[i] != 1){
            temp.push_back(i);
            flag[i] = 1;
            queen();
            temp.pop_back();
            flag[i] = 0;
        }
    }
}

int main(){
    memset(flag, 0, sizeof(flag));
    int n, index;
    queen();
    // for(int i = 0; i < res.size(); i++){
    //     memset(state, 0, sizeof(state));
    //     cout << "No. " << i+1 << endl;
    //     for(int j = 0; j < res[i].size(); j++){
    //         state[res[i][j]][j+1] = 1;
    //     }
    //     for(int x = 1; x <= 8; x++){
    //         for(int y = 1; y <= 8; y++){
    //             cout << state[x][y] << ' ';
    //         }
    //         cout << endl;
    //     }
    // }
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> index;
            index = index - 1;
            for(int i = 0; i < res[index].size(); i++){
                cout << res[index][i];
            }
            cout << endl;
        }
    }
    return 0;
}