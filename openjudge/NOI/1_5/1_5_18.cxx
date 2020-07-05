/*
    题目名字: 斐波那契数列
    题目编号: 7783
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>

int main(){
    int k;
    int a, b, temp;
    scanf("%d", &k);
    a = 1; b = 1;
    for(int i = 3; i <= k; i++){
        temp = b;
        b = a + b;
        a = temp;
    }
    printf("%d\n", b);

}

// #include <stdio.h>

// int i;

// int fibonacci(int a, int b, int k){
//     if(i == k) return b;
//     i++;
//     return fibonacci(b, a+b, k);
// }

// int main(){
//     int k;
//     scanf("%d", &k);
//     i = 2;
//     printf("%d\n", fibonacci(1, 1, k));
// }