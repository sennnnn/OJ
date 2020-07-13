#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int a, b, k;
    while(cin >> a >> b >> k){
        int flag = 1;
        int sum = a + b;
        for(int i = 1; i <= k; i++){
            if(a%10 != b%10) flag = 0;
            a /= 10;
            b /= 10;
        }
        if(flag == 0) cout << sum << endl;
        else cout << -1 << endl;
    }
    return 0;
}