/*
    题目名字: 字符环
    题目编号: 2755
    日期: 2020 年 6 月 25 日
*/

#include <stdio.h>
#include <string.h>

int main(){
    int count, len1, len2;
    int i_match, j_match, len_pub;
    char s1[300], s2[300];
    scanf("%s %s", s1, s2);
    count = 0; len1 = strlen(s1); len2 = strlen(s2);
    len_pub = 0;
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            i_match = i; j_match = j;
            count = 0;
            while(1){
                if(s1[i_match] == s2[j_match]){
                    i_match++; 
                    j_match++;
                    count++;
                    if(count == len1 || count == len2){
                        if(count > len_pub) len_pub = count;
                        break;
                    } 
                }else{
                    if(count > len_pub) len_pub = count;
                    break;
                }
                i_match = i_match%len1; 
                j_match = j_match%len2;
            }
        }
    }
    printf("%d\n", len_pub);
}