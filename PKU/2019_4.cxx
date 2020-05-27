#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>

using namespace std;

int max_count[1001];

int MaxAscendOrderSubSum(int list[], int n){
    int max_ = -9999999;
    int sum = 0;
    memset(max_count, 0, sizeof(int)*1001);
    max_count[0] = list[0];
    for(int i = 1; i < n; i++){
        max_count[i] = list[i];
        for(int j = 0; j < i; j++){
            if(list[j] < list[i]){
                if(max_count[j] + list[i] > max_count[i]){
                    max_count[i] = max_count[j] + list[i];
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        if(max_count[i] > max_) max_ = max_count[i];
    }

    return max_;
}

int main(){
    int storage[1001];
    int n;
    int max_sum;
    while(scanf("%d", &n) != EOF){
        getchar();
        memset(storage, 0, sizeof(int)*1001);
        for(int i = 0; i < n; i++){
            scanf("%d", &storage[i]);
        }
        max_sum = MaxAscendOrderSubSum(storage, n);
        printf("%d\n", max_sum);
    }
}