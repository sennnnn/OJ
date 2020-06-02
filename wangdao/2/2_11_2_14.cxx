#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(float a, float b){
    return a > b;
}

void sort_(float *a, int *b, int n){
    float temp_f;
    int temp_i;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(!cmp(a[j], a[j+1])){
                temp_f = a[j];temp_i = b[j];
                a[j] = a[j+1];b[j] = b[j+1];
                a[j+1] = temp_f;b[j+1] = temp_i;
            }
        }
    }
}

int main(){
    int J[1000],F[1000];
    float val[1000];
    int n,m;
    float get;
    int i;
    while(scanf("%d %d", &m, &n) != EOF && m != -1 && n != -1){
        get = 0;
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d %d", &J[i], &F[i]);
            val[i] = (float)J[i]/F[i];
            getchar();
        }
        sort_(val, F, n);
        i = 0;
        while(m != 0 || i < n){
            if(m >= F[i]){
                m -= F[i];
                get += val[i]*F[i];
            }else{
                get += val[i]*m;
                m = 0;
            }
            i++;
        }
        printf("%f\n", get);
    }
    return 0;
}