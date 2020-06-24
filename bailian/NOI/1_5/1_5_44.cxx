/*
    题目名字: 第 n 小的质数
    题目编号: 8163
    日期: 2020 年 6 月 24 日
    备注: 判断数字 x 是否为质数最快捷的方法是只要判断 2 ~ sqrt(x) 是否能够被其整除
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
    int temp, count;
    scanf("%d", &n);
    temp = 1;
    count = 0;
    while(1){
        temp++;
        if(temp != 2 && temp % 2 == 0) continue;
        if(judge(temp)) {
            count++;
        }
        if(count == n) break;
    }
    printf("%d\n", temp);
}