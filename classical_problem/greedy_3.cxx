#include <stdio.h>


// 九度练习题三

bool cmp(float a, float b){
    return a < b;
}

bool cmp(int a, int b){
    return a < b;
}

void sort_(float *a, int *b, int n){
    int temp_i;
    float temp_f;
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            if(!cmp(b[j], b[j+1])){
                temp_i = b[j]; b[j] = b[j+1]; b[j+1] = temp_i;
                temp_f = a[j]; a[j] = b[j+1]; b[j+1] = temp_f;
            }
        }
    }
}

int ifcheaper(int s, int e, float *p){
    float temp = p[s];
    float min = temp;
    int index = -1;
    for(int i = s+1; i <= e; i++){
        if(p[i] <= min){
            min = p[i];
            index = i;
        }
    }
    return index;
}


int main(){
    int Cmax, D, Davg, N;
    float p[500];
    int d[500];
    float cost;
    int longest_dis;
    while(scanf("%d %d %d %d", &Cmax, &D, &Davg, &N) != EOF){
        for(int i = 0; i < N; i++){
            scanf("%f %d", &d[i], &p[i]);
        }
        sort_(p, d, N);
        if(d[0] != 0) printf("The maximum travel distance = 0.00");
        longest_dis = 0;
        cost = 0.00;
        int acc_dis = 0;
        int acc_local_dis = 0;
        int maxRunDis = Cmax*Davg;
        int i = 0;
        int j = 0;
        while(acc_dis < D){
            i = j;
            while(1){
                if(j == N) break;
                acc_local_dis += d[j];
                if(acc_local_dis > maxRunDis) break;
                j++;
            }
            if(i == j) break;
            j = ifcheaper(i, j, p);
            if(j == -1){
                cost += Cmax*p[i];
            }else{

            }
        }

    }
}