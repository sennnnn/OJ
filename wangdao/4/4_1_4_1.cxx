#include <iostream>
#include <cstring>

using namespace std;

int main(){
    long long a, b;
    long long s1[100];
    long long s2[100];
    long long res;
    cin >> a >> b;
    int l1, l2;
    l1 = 0;
    l2 = 0;
    while(a != 0){
        s1[l1++] = a%10;
        a /= 10;
    }
    while(b != 0){
        s2[l2++] = b%10;
        b /= 10;
    }
    res = 0;
    for(int i = 0; i < l1; i++){
        for(int j = 0; j < l2; j++){
            res += s1[i]*s2[j];
        }
    }
    cout << res << endl;
}