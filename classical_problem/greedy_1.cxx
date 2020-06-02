#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

// HDU 2570 Accepted 0Ms

int main(){
    int c;
    int n, V, W;
    int con[10000];
    float con_e;
    int end_v;
    float temp;
    while(scanf("%d", &c) != EOF){
        for(int i = 0; i < c; i++){
            scanf("%d %d %d", &n, &V, &W);
            for(int j = 0; j < n; j++){
                scanf("%d", &con[j]);
            }
            sort(con, con + n, cmp);
            end_v = V;
            con_e = con[0];
            if(con[0] > W) printf("%d %.2f\n", 0, 0);
            else{
                for(int k = 1; k < n; k++){
                    temp = (con[k]*V + con_e*end_v)/(end_v+V);
                    if(temp <= W){
                        end_v += V;
                        con_e = temp;
                    }
                }
                printf("%d %.2f\n", end_v, con_e/100);
            }
        }
    }
}