#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// POJ 1961 969 ms

int next[1000001];

void get_next(char *s, int len){
    int i, j;
    next[0] = 0;
    for(i = 1; i < len; i++){
        j = next[i-1];

        while(s[i] != s[j] && j != 0) j = next[j-1];

        if(s[i] == s[j]) next[i] = j+1;
        else next[i] = 0;
    }
}

void search(char *s, int len, int index){
    int cnt;
    printf("Test case #%d\n", index);
    for(int i = 2; i <= len; i++){
        if(i%(i - next[i-1]) == 0){
            cnt = i/(i-next[i-1]);
            if(cnt != 1){
                printf("%d %d\n", i, cnt);
            }
        }
    }
    printf("\n");
}


int main(){
    int n;
    char s[1000001];
    int time = 0;
    while(scanf("%d", &n) != EOF && n != 0){
        time++;
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%c", &s[i]);
        }
        s[n] = '\0';
        getchar();
        get_next(s, n);
        search(s, n, time);
    }
}