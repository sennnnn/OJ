#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main(){
    int n;
    int buf[3000];
    int buf_[3000];
    int flag;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &buf[i]);
            if(i > 0) buf_[i-1] = abs(buf[i] - buf[i-1]);
        }
        sort(buf_, buf_+(n-1), cmp);
        flag = 0;
        for(int i = 0; i < n-1; i++){
            if(buf_[i] == buf_[i-1]) flag = 1;
        }
        if(flag) printf("Not jolly");
        else printf("Jolly");
    }
}