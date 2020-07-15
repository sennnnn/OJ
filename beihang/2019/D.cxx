/*
    题目来源: http://www.noobdream.com/DreamJudge/Contest/45/1379/?Problem=D
    日期: 2020 年 7 月 15 日
*/

#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int n;
    double x, res;
    while(cin >> x){
        cin >> n;
        res = x;
        for(int i = 0; i < n; i++){
            res = res*2/3 + x/(3*res*res);
        }
        printf("%.6lf\n", res);
    }
}