#include <iostream>

using namespace std;

int main(){
    int N, res, flag;
    while(cin >> N){
        res = N*N;
        flag = 1;
        while(N != 0){
            if(N%10 != res%10) flag = 0;
            N /= 10;
            res /= 10;
        }
        if(flag) cout << "Yes!" << endl;
        else cout << "No!" << endl;
    }
    return 0;
}