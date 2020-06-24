/*
    题目名字: 有趣的跳跃
    题目编号: 1577
    日期: 2020 年 6 月 23 日
*/

#include <math.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int main(){
    int n;
    int l[3000];
    int abs_result[3000];
    int flag;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &l[i]);
    }
    if(n == 1) flag = 1;
    else{
        for(int i = 0; i < n-1; i++){
            abs_result[i] = abs(l[i] - l[i+1]);
        }
        sort(abs_result, abs_result+n-1, cmp);
        flag = 1;
        for(int i = 0; i < n-1; i++){
            if(abs_result[i] != i+1){
                flag = 0;
            }
        }
    }
    
    if(flag) printf("Jolly\n");
    else printf("Not jolly\n");
}