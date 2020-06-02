#define MAX 50000

void substr(char *s, char *get, int start, int end){
    int len = end-start;
    int i;
    for(i = 0; i < len; i++){
        get[i] = s[start++];
    }
    get[i] = '\0';
}

int contain(char *s, char letter){
    int index = 0;
    while(s[index]){
        if(s[index++] == letter){
            return 1;
        }
    }
    return 0;
}

void show(char *s){
    int index = 0;
    while(s[index]){
        printf("%c", s[index++]);
    }
    printf("\n");
}

int lengthOfLongestSubstring(char * s){
    int i = 0;
    int j = 0;
    int result = 0;
    char sub[MAX] = {0};
    while(s[i] && s[j]){
        substr(s, sub, i, j);
        if(!contain(sub, s[j])){
            j++;
        }else{
            if(result < (j-i)){
                result = j-i;
            }
            i++;
        }
    }
    if(result < (j-i)){
        result = j-i;
    }
    return result;
}