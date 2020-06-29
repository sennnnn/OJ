/*
    题目名字: 错误检测
    题目编号: 7742
    日期: 2020 年 6 月 29 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int n;
    int s[110][110];
    int r[110], r_count;
    int c[110], c_count;
    memset(s, 0, sizeof(s)); memset(r, 0 ,sizeof(r)); memset(c, 0, sizeof(c));
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &s[i][j]);
        }
    }
    r_count = 0; c_count = 0;
    // 预处理
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i][j] == 1) r[i]++;
        }
        if(r[i]%2 != 0) r_count++;
    }
    for(int j = 1; j <= n; j++){
        for(int i = 1; i <= n; i++){
            if(s[i][j] == 1) c[j]++;
        }
        if(c[j]%2 != 0) c_count++;
    }
    if(r_count == 0 && c_count == 0) printf("OK\n");
    else if(r_count == 1 && c_count == 1) {
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(r[i]%2 != 0 && c[j]%2 != 0) printf("%d %d\n", i, j);
            }
        }
    }else printf("Corrupt\n");
    
    
}