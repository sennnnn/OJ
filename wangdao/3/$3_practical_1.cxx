#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int main(){
    long long m, n, sum, base, sub_r;
    long long bl, br;
    while(cin >> m >> n){
        if(m == 0 && n == 0) break;
        sum = 0;
        base = 1;
        bl = br = 1;
        while(1){
            if(bl <= n && br >= n) break;
            bl = 2 * bl;
            br = 2 * br + 1;
        }
        sub_r = m;
        while(1){
            if(bl <= m && br >= m) break;
            sum += base;
            base  = 2 * base;
            m     = 2 * m;
            sub_r = 2 * sub_r + 1;
        }
        for(long long i = m; i <= min(n, sub_r); i++){
            sum++;
        }
        cout << sum << endl;
    }
    return 0;
}