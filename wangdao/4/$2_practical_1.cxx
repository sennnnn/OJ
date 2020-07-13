#include <iostream>
#include <cstring>

using namespace std;

bool check(int temp){
    int res = temp*9;
    int s1[6];
    int s2[6];
    int index1, index2;
    memset(s1, 0, sizeof(s1));
    memset(s2, 0, sizeof(s2));
    index1 = 0;
    index2 = 0;
    while(temp != 0){
        s1[index1++] = temp%10;
        temp /= 10;
    }
    while(res != 0){
        s2[index2++] = res%10;
        res /= 10;
    }
    if(index2 != index1) return false;
    int flag = 1;
    for(int i = 0; i < 4; i++){
        if(s1[i] != s2[3-i]) flag = 0;
    }
    if(flag) return true;
    return false;
}

int main(){
    for(int i = 1000; i <= 9999; i++){
        if(check(i)) cout << i << endl;
    }
}