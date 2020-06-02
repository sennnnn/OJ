#include <stdio.h>
#include <string.h>


// POJ 2752 
// brute force Time Limit Exceed

void search_1(char *s, int len){
    int flag;
    for(int i = 1; i < len; i++){
        flag = 1;        
        for(int j = 0; j < i; j++){
            if(s[j] != s[len-i+j]) {
                flag = 0;
                break;
            }
        }
        if(flag) printf("%d ", i);
    }
    printf("%d", len);
    printf("\n");
}

// KMP brute force Time Limit Exceed

int next[400001];

void get_next(char *s, int len){
    int i = 0, j = 0;
    next[0] = 0;
    for(int i = 1; i < len; i++){
        j = next[i-1];

        while(s[i] != s[j] && j != 0) j = next[j-1];

        if(s[i] == s[j]) next[i] = j+1; 
        else next[i] = 0;
    }
}

int search(char *s, char *p, int n, int m){
    int i = 0; int j = 0;
    while(i < n){
        if(s[i] == s[j]){
            i++;j++;
        }else if(j == 0){
            i++;
        }else{
            j = next[j-1];
        }
        if(j == m){
            j = next[j-1];
            
            if(i == n) {
                return i;
            }
        }
    }
    return 0;
}

void search_2(char *s, int len){
    int temp;
    for(int i = 1; i < len; i++){
        memset(next, 0, sizeof(int)*i);
        get_next(s, i);
        temp = search(s, s, len, i);
        
        if(temp != 0) printf("%d ", i);
    }
    printf("%d\n", len);
}


// KMP use of next matrix Accepted 454ms

void search_3(char *s, int len){
    int result[400001];
    int count = 0;
    int i = len;
    get_next(s, len);
    while(i > 0){
        result[count++] = i;
        i = next[i-1];
    }
    for(int i = count-1; i >= 0; i--){
        printf("%d ", result[i]);
    }
    printf("\n");

}


int main(){
    char s[400001];
    int len;
    
    while(scanf("%s", s) != EOF){
        len = strlen(s);
        search_3(s, len);
    }
}
