/*
    题目名字: 质因数分解
    题目编号: 7922
    日期: 2020 年 6 月 24 日
*/

#include <stdio.h>
#include <math.h>

bool judge(int num){
    for(int i = 2; i <= sqrt(num); i++){
        if(num%i == 0) return false;
    }
    return true;
}

int main(){
    int n;
    int i, next;
    scanf("%d", &n);
    for(i = 2; i <= n/2; i++){
        if(judge(i)){
            if(n%i != 0) continue;
            next = n/i;
            if(judge(next)) break;
        }
    }
    if(next > i) printf("%d\n", next);
    else printf("%d\n", i);
}