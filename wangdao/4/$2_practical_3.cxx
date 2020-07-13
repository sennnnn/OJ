#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char state[10000];
    int n, i, sum;
    while(cin >> state){
        if(state[0] == '0') break;
        n = strlen(state);
        while(n > 1){
            sum = 0;
            for(i = 0; i < n; i++){
                sum += state[i] - '0';
            }
            memset(state, 0, sizeof(state));
            i = 0;
            while(sum != 0){
                state[i++] = sum%10 + '0';
                sum /= 10;
            }
            n = strlen(state);
        }
        cout << state[0] << endl;
    }
}