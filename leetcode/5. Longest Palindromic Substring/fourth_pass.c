#include <stdlib.h>

void substr(char *s, char *get, int start, int end){
    int index = 0;
    for(int i = start; i < end; i++){
        get[index++] = s[i];
    }
    get[index] = '\0';
}

int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

void preprocess(char *s ,char *ss ,int s_length){
    int index = 0;
    for(int i = 0; i < s_length; i++){
        ss[index++] = '#';
        ss[index++] = s[i];
    }
    ss[index++] = '#';
    ss[index] = '\0';
}

int min(int a, int b){
    return a < b ? a : b;
}

char *longestPalindrome(char * s){
    int s_length = len(s);
    if(s_length == 0) return "";
    char *ss = (char *)malloc(sizeof(char)*(2*s_length+2));
    int r[2*s_length+1];
    preprocess(s, ss, s_length);
    int mx = 1;
    int c = 0;
    r[0] = 1;
    int max_len = 0;
    int sub_i = 0,sub_j = 0;
    for(int i = 1; i < 2*s_length+1; i++){
        if(i < mx) r[i] = min(mx-i+1, r[2*c-i]);
        else{
            r[i] = 1;
        }
        while(i - r[i] >= 0 && i + r[i] < 2*s_length+1 && ss[i-r[i]] == ss[i+r[i]]) r[i]++; 
        if(r[i] + i - i > c){
            c = i;
            mx = i + r[i] - 1;
        }
        if(r[i] - 1 > max_len){
            sub_i = i - r[i] + 1;
            sub_j = i + r[i] - 1;
            max_len = r[i] - 1;
        }
    }
    sub_i = sub_i/2;
    sub_j = sub_j/2 - 1;
    char *result = (char *)malloc(sizeof(char)*(max_len+1));
    substr(s, result, sub_i, sub_j+1);
    return result;
}