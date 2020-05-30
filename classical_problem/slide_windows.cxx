#include <stdio.h>
#include <string.h>

// leetcode 3 Accepted 4ms

int ascii_hash[129];

int lengthOfLongestSubstring(char *s){
    int left = 0, right = 0;
    int len = strlen(s);
    int max = 0;
    char temp;
    while(right < len){
        temp = s[right];
        ascii_hash[(int)temp]++;
        if(ascii_hash[(int)temp] != 1){
            while(left <= right){
                ascii_hash[(int)s[left++]]--;
                if(ascii_hash[(int)temp] == 1) break;
            }
        }
        if(right - left + 1 > max){
            max = right - left + 1;
        }
        right++;
    }

    return max;
}

int main(){
    memset(ascii_hash, 0, sizeof(ascii_hash));
    char s[10000];
    int count;
    while(scanf("%s", s) != EOF){
        count = lengthOfLongestSubstring(s);
        printf("%d\n", count);
    }
    
}

