/*
    题目名字: 二叉树
    编号: 1790
    日期: 2020 年 7 月 8 日
*/

#include <iostream>
#include <cstring>

using namespace std;

int min(int a, int b){
    if(a < b) return a;
    else return b;
}

int main(){
    int m, n, ct;
    int temp;
    int base;
    int ls, le;
    int subs, sube;
    while(cin >> m >> n){
        if(n == 0 && m == 0)  break;
        if(m == 1) cout << n << endl;
        else{
            ct = 0;
            ls = 1; le = 1;
            while(!(ls <= n && le >= n)) {
                ls = ls*2;
                le = le*2 + 1;
            }
            base = 1;
            temp = m;
            sube = m;
            while(!(ls <= temp && temp <= le)){
                ct += base;
                base *= 2;
                temp *= 2;
                sube = sube*2 + 1;
            }
            n = min(sube, n);
            for(int i = temp; i <= n; i++) ct++;
            cout << ct << endl;
        }
    }
    return 0;
}