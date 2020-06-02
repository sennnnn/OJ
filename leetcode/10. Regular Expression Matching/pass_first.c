#include <stdio.h>
#include <stdlib.h>

#define bool _Bool
#define false 0
#define true 1

void substr(char *s, char *get, int i, int j){
    int index = 0;
    for(int k = i; k < j; k++){
        get[index++] = s[k];
    }
    get[index] = '\0';
}

int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

bool strcmp_cus(char *a, char *b){
    int i = 0, j = 0;
    while(a[i] && b[j]){
        if(a[i] != b[j]) return false;
    }
    if(a[i] || a[j]) return false;
    return true;
}

bool isMatch(char * s, char * p){
    if(strcmp_cus(p, "")) return strcmp_cus(s, "");
    int flag = s[0] && (s[0] == p[0] || p[0] == '.');

    int len_p = len(p);
    int len_s = len(s);

    char p_get[len_p+1];
    char s_get[len_s+1];

    if(len_p >= 2 && p[1] == '*'){
        substr(p, p_get, 2, len_p);
        substr(s, s_get, 1, len_s);
        return isMatch(s, p_get) || flag && isMatch(s_get, p);
    }else{
        substr(s, s_get, 1, len_s); 
        substr(p, p_get, 1, len_p);
        return flag && isMatch(s_get, p_get);
    }
}

