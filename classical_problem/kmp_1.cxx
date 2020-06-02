#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int next[1000001];

// POJ 2406 Accepted 125ms

void get_next(char *s, int len){
    int i = 0, j = 0;
    next[0] = 0;
    for(i = 1; i < len; i++){
        j = next[i-1];

        while(s[i] != s[j] && j != 0) j = next[j-1];

        if(s[i] == s[j]) next[i] = j+1;
        else next[i] = 0;
    }
}


int pow_get(int *next, int len){
    int base;
    for(int i = 0; i < len; i++) {
        if(next[i] != 0){
            base = i;
            break;
        }
    }
    if(len%base == 0){
        return len/base;
    }else return 1;
}


int main(){
    char s[1000001];
    int len;
    int n;
    while(scanf("%s", s) != EOF && s[0] != '.'){
        len = strlen(s);
        get_next(s, len);
        
        if(len%(len - next[len-1]) == 0){
            printf("%d\n", len/(len - next[len-1]));
        }else printf("1\n");
    }
}