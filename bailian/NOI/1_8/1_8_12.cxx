/*
    题目名字: 变幻的矩阵
    题目编号: 6683
    日期: 2020 年 6 月 28 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int N, i, j, len1, len2, len3, len4;
    char s1[12][12];
    char s2[12][12];
    char temp;
    scanf("%d", &N);
    getchar();
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            scanf("%c", &s1[i][j]);
            scanf("%c", &temp);
            // printf("%d-%d: %c %c\n", i, j, s1[i][j], temp);
        }
    }
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            scanf("%c", &s2[i][j]);
            scanf("%c", &temp);
            // printf("%d-%d: %c %c\n", i, j, s2[i][j], temp);
        }
    }
    // printf("\n");
    // for(i = 1; i <= N; i++){
    //     for(j = 1; j <= N; j++){
    //         printf("%c", s1[i][j]);
    //     }
    //     printf("\n");
    // }
    // printf("\n");
    // for(i = 1; i <= N; i++){
    //     for(j = 1; j <= N; j++){
    //         printf("%c", s2[i][j]);
    //     }
    //     printf("\n");
    // }
    len1 = 0; len2 = 0; len3 = 0; len4 = 0;
    for(i = 1; i <= N; i++){
        for(j = 1; j <= N; j++){
            if(s1[i][j] == s2[j][N+1-i]) len1++;
            if(s1[i][j] == s2[N+1-j][i]) len2++;
            if(s1[i][j] == s2[N+1-i][N+1-j]) len3++;
            if(s1[i][j] == s2[i][j]) len4++;
        }
    }
    if(len1 == N*N) printf("1\n");
    else if(len2 == N*N) printf("2\n");
    else if(len3 == N*N) printf("3\n");
    else if(len4 == N*N) printf("4\n");
    else printf("5\n");
    return 0;
}