/*
    题目名字: 回文子串
    题目编号: 7603
    日期: 2020 年 6 月 26 日
*/

// #include <stdio.h>
// #include <string.h>

// int main(){
//     int len, count;
//     char s[600];
//     int sub[600][2];
//     scanf("%s", s);
//     len = strlen(s); count = 0;
//     for(int i = 1; i < len; i++){
//         for(int j = 0; j < len-i; j++){
//             int flag = 1;
//             for(int k = j; k <= (j+j+i)/2; k++){
//                 if(s[k] != s[j+j+i-k]) flag = 0;
//             }
//             if(flag){
//                 sub[count][0] = j; 
//                 sub[count][1] = j+i;
//                 count++;
//             }
//         }
//     }
//     for(int i = 0; i < count; i++){
//         for(int j = sub[i][0]; j <= sub[i][1]; j++){
//             printf("%c", s[j]);
//         }
//         printf("\n");
//     }
// }

#include<stdio.h>
#include<string.h>
int f(char a[],int i,int j)
{
    int k=0;
    int n=i,m=j;
    while(i<=j)
    {
        if(a[i]!=a[j]){k=1;}
        i++;
        j--;
    }
    if(k==0)
    {
        for(n=i;n<=m;n++)
        printf("%c",a[n]);
        printf("\n");
    }
    return 0;
}
main()
{
char a[20];
int i,j,n;
scanf("%s",a);
for(i=2;i<=strlen(a);i++)
{
for(j=0;j+i<=strlen(a);j++)
{
n=f(a,j,j+i-1);
}
}
return 0;
}