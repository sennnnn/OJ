#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// leetcode 76 8ms

int ascii_hash_raw[129];
int ascii_hash[129];

char *minWindow(char *s, char *t){
    memset(ascii_hash, -1, sizeof(ascii_hash));
    memset(ascii_hash_raw, 0, sizeof(ascii_hash));
    int left = 0, right = 0;
    int min_left = 0, min_right = 0;
    int len_s = strlen(s), len_t = strlen(t);
    int min = len_s + 1;
    int miss_type = 0;
    for(int i = 0; i < len_t; i++){
        ascii_hash_raw[(int)t[i]]++;
        ascii_hash[(int)t[i]] = ascii_hash_raw[(int)t[i]];
        miss_type++;
    }
    char temp;
    while(right < len_s){
        temp = s[right];
        if(ascii_hash_raw[(int)temp] != 0) ascii_hash[(int)temp]--;
        if(ascii_hash[(int)temp] < ascii_hash_raw[(int)temp] && ascii_hash[(int)temp] >= 0) miss_type--;
        while(miss_type == 0 && left <= right)
        {
            if(right - left + 1 >= len_t && right - left + 1 < min){
                min = right - left + 1;
                min_left = left;
                min_right = right;
            }
            if(ascii_hash_raw[(int)s[left]] != 0) ascii_hash[(int)s[left]]++;
            if(ascii_hash[(int)s[left]] > 0) miss_type++;
            left++;
        }
        right++;
    }
    if(min == len_s + 1) min = 0;
    char *ret = (char *)malloc(sizeof(char)*(min+1));
    for(int i = 0; i < min; i++){
        ret[i] = s[min_left+i];
    }
    ret[min] = '\0';
    return ret;
}

int main(){
    char s[10000];
    char t[10000];
    char *accept;
    while(scanf("%s %s", s, t) != EOF){
        accept = minWindow(s, t);
        printf("%s\n", accept);
    }

}