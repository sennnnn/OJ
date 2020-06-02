#define SIZE 1000

void substr(char *s, char *get, int start, int end){
    int index = 0;
    for(int i = start; i < end; i++){
        get[index++] = s[i];
    }
    get[index] = '\0';
}

int test(char *s, int len){
    for(int i = 0; i < len/2; i++){
        if(s[i] != s[len - i - 1]) return 0;
    }
    return 1;
}

int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

char * longestPalindrome(char * s){
    int i = 0, j = 0;
    int test_flag = 0;
    int s_length = len(s);
    if(s_length == 0) return "";
    char sub[SIZE] = {0};int sub_len = 0;
    char max[SIZE] = {0};int max_len = 0;
    char *result;
    while(s[i]){
        j = i;
        while(s[j]){
            substr(s, sub, i, j+1);
            sub_len = j-i+1;
            test_flag = test(sub, sub_len);
            if(test_flag){
                if(max_len < sub_len){
                    substr(s, max, i, j+1);
                    max_len = sub_len;
                }
            }
            j++;
        }
        i++;
    }
    result = max;
    return result;
}