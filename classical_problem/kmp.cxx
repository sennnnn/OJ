#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// POJ 3461
// brute force Time Limit Exceeded 
int search_1(char *a, char *b, int n, int m){
    int count = 0;
    int i, j;
    for(i = 0; i < n-m+1; i++){
        for(j = 0; j < m; j++){
            if(a[i + j] != b[j]) break;
        }
        if(j == m) count++;
    }
    return count;
}

// KMP template method Accepted 110 MS
int next[10001];

void get_next(char *p, int *next, int m){
    int i, j;
    next[0] = 0;
    for(i = 1; i < m; i++){
        j = next[i-1];

        while(p[i] != p[j] && j != 0) j = next[j-1];
        
        if(p[j] == p[i]) next[i] = j+1;
        else next[i] = 0;
    }
}

int search_2(char *s, char *p, int n, int m){
    int i = 0, j = 0;
    int count = 0;
    while(i < n){
        if(s[i] == p[j]){
            i++;j++;
        }else if(j == 0){
            i++;
        }else{
            j = next[j-1];    
        }
        if(j == m){
            count++;
            j = next[j-1];
        }
    }
    
    return count;
}

// hash method
// BKDRhash ( merit of this hash algorithm: https://blog.csdn.net/MBuger/article/details/61663097)
typedef unsigned long long ull;
const int seed = 231;
const int M = 1e9 + 7;

// ull a[maxn];
// ull hash[maxn];

// ull BKRDhash(char *s){
//     ull h = 0;
//     for(int i = 0; )
// }

int get_hash(char *s, int len){
    int res = 0;
    for(int i = 0; i < len; i++){
        res = (ull)(res * seed + s[i]) % M;
    }
    return res;
}

bool cmp(char *s1, char *s2, int len){
    return get_hash(s1, len) == get_hash(s2, len);
}

int search_3(char *s, char *p, int n, int m){
    int count = 0;
    for(int i = 0; i < n-m+1; i++){
        if(cmp(s+i, p, m)) count++;
    }
    return count;
}

int main(){
    char s[1000001];
    char p[10001];
    int n;
    int count;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%s", p);
            scanf("%s", s);
            get_next(p, next, strlen(p));
            count = search_3(s, p, strlen(s), strlen(p));
            printf("%d\n", count);
        }
    }
}