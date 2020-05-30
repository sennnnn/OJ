#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// leetcode 438 28ms

int ascii_hash[128];
int ascii_hash_raw[128];

int *findAnagrams(char *s, char *p, int *returnSize){
    memset(ascii_hash, -1, sizeof(ascii_hash));
    memset(ascii_hash_raw, 0, sizeof(ascii_hash_raw));
    int left = 0, right = 0;
    int len_s = strlen(s), len_p = strlen(p);
    int miss_type = 0;
    for(int i = 0; i < len_p; i++){
        ascii_hash_raw[(int)p[i]]++;
        ascii_hash[(int)p[i]] = ascii_hash_raw[(int)p[i]];
        miss_type++;
    }
    char temp;
    int *ret = (int *)malloc(sizeof(int)*20100);
    int Size = 0;
    while(right < len_s){
        temp = s[right];
        if(ascii_hash_raw[(int)temp] != 0) ascii_hash[(int)temp]--;
        if(ascii_hash[(int)temp] < ascii_hash_raw[(int)temp] && ascii_hash[(int)temp] >= 0) miss_type--;
        while(miss_type == 0 && left <= right)
        {
            if(right - left + 1 == len_p){
                ret[Size++] = left;
            }
            if(ascii_hash_raw[(int)s[left]] != 0) ascii_hash[(int)s[left]]++;
            if(ascii_hash[(int)s[left]] > 0) miss_type++;
            left++;
        }
        right++;
    }
    *returnSize = Size;
    return ret;
}


int main(){
    char s[20100];
    char p[20100];
    int Size;
    int *ret;
    while(scanf("%s %s", s, p) != EOF){
        ret = findAnagrams(s, p, &Size);
        for(int i = 0; i < Size; i++){
            printf("%d ", ret[i]);
        }
        printf("\n");
    }

}