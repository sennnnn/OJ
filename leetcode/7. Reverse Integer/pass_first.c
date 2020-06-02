#include <stdio.h>

int reverse(int x){
    if(x == -2147483648) return 0;
    int flag = x > 0 ? 1 : -1;
    x = x*flag;
    double out = 0;
    int bit = 0;
    while(x){
        bit = x%10;
        out = out*10 + bit;
        if(out > 2147483647.0) return 0;
        x = x/10;
    }
    return (int)out*flag;
}

int main(){
    int input = -2147483648;
    printf("%d\n", reverse(input));
}