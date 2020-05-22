#include <stdio.h>
#include <algorithm>
using namespace std;
bool cmp(int a, int b){
    return a < b;
}
int main(){
    int n;
    int buf[1001];
    while(scanf("%d", &n)){
        for(int i = 0; i < n; i++){
            scanf("%d", &buf[i]);
        }
        if(n != 1){
            sort(buf, buf+n, cmp);
            printf("%d\n", buf[n-1]);
            for(int i = 0; i < n-1; i++){
                printf("%d ", buf[i]);
            }
            printf("\n");
        }else{
            printf("%d\n", buf[n-1]);
            printf("%d\n", -1);
        }
    }
    return 0;
}