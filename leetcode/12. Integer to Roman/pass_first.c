#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool _Bool
#define false 0
#define true 1

void add(char *s, char *ss){
    int index = 0;
    int index_ = 0;
    while(s[index]) index++;
    while(ss[index_]) s[index++] = ss[index_++];
    s[index] = 0;
}

void init(char *s, int len){
    int index = 0;
    for(int i = 0; i < len; i++){
        s[i] = 0;
    }
}

char * intToRoman(int num){
    char *result = (char *)malloc(sizeof(char)*100);
    init(result, 100);
    int temp;
    int s_length;
    int index = 0;
    for(int i = 0; i < num/1000; i++){
        result[index++] = 'M';
    }
    num = num%1000;
    if(num >= 900){
        result[index++] = 'C';
        result[index++] = 'M';
    }
    num = num%900;
    for(int i = 0; i < num/500; i++){
        result[index++] = 'D';
    }
    num = num%500;
    if(num >= 400){
        result[index++] = 'C';
        result[index++] = 'D';
    }
    num = num%400;
    for(int i = 0; i < num/100; i++){
        result[index++] = 'C';
    }
    num = num%100;
    if(num >= 90){
        result[index++] = 'X';
        result[index++] = 'C';
    }
    num = num%90;
    for(int i = 0; i < num/50; i++){
        result[index++] = 'L';
    }
    num = num%50;
    if(num >= 40){
        result[index++] = 'X';
        result[index++] = 'L';
    }
    num = num%40;
    for(int i = 0; i < num/10; i++){
        result[index++] = 'X';
    }
    num = num%10;
    if(num >= 9){
        result[index++] = 'I';
        result[index++] = 'X';
    }
    num = num%9;
    for(int i = 0; i < num/5; i++){
        result[index++] = 'V';
    }
    num = num%5;
    if(num >= 4){
        result[index++] = 'I';
        result[index++] = 'V';
    }
    num = num%4;
    for(int i = 0; i < num; i++){
        result[index++] = 'I';
    }
    result[index] = 0;
    return result;
}

int main(){
    char *s1 = (char *)malloc(sizeof(char)*10);
    init(s1, 10);
    s1[0] = 'a';
    add (s1, "123") ;
    printf("%s", s1) ;
}