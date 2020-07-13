#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int l;
char s[8];
int flag[8];
vector<char> temp;

void search(){
    if(temp.size() == l) {
        for(int i = 0; i < l; i++){
            cout << temp[i];
        }
        cout << endl;
        return ;
    }
    for(int i = 0; i < l; i++){
        if(flag[i] == 0){
            flag[i] = 1;
            temp.push_back(s[i]);
            search();
            temp.pop_back();
            flag[i] = 0;
        }
    }
    return ;
}

int main(){
    memset(s, 0, sizeof(s));
    memset(flag, 0, sizeof(flag));
    cin >> s;
    l = strlen(s);
    search();
}