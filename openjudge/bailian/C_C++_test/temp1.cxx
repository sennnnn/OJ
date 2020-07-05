#include <stdio.h>
#include <string.h>

int abs(int value){
    if(value < 0) return value*-1;
    return value;
}

int main(){
    int n, k;
    int diff;
    int num1, num2;
    int _list[1010];
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &_list[i]);
    }
    diff = 30000000;
    for(int i = 0; i < n; i++){
        for(int j = i+1; j < n; j++){
            if(_list[i] + _list[j] <= k){
                if(abs(_list[i] + _list[j] - k) <= diff){
                    num1 = _list[i];
                    num2 = _list[j];
                    diff = abs(_list[i] + _list[j] - k);
                }
            }
        }
    }
    printf("%d\n", num1 + num2);
    return 0;
}
