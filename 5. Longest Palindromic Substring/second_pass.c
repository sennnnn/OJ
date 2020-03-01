void substr(char *s, char *get, int start, int end){
    int index = 0;
    for(int i = start; i < end; i++){
        get[index++] = s[i];
    }
    get[index] = '\0';
}

int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

void init(_Bool *target, int len){
    for(int i = 0; i < len; i++){
        target[i] = 0;
    }
}

char *longestPalindrome(char * s){
    int i = 0, j = 0;
    int s_length = len(s);
    if(s_length == 0) return "";
    int max_len = 0;
    _Bool flag[s_length][s_length];
    // all zero initialize
    for(int index = 0; index < s_length; index++){
        init(&(flag[index]), s_length);
    }
    int sub_i, sub_j;
    for(; j < s_length; j++){
        i = 0;
        flag[j][j] = 1;
        for(; i <= j; i++){
            if(s[i] == s[j]){
                flag[i][j] = j-i+1 <= 2 ? 1 : flag[i + 1][j - 1];
            }
            if(flag[i][j]){
                if(max_len <= j-i+1){
                    sub_i = i;
                    sub_j = j;
                    max_len = j-i+1;
                }
            }
        }
    }
    // 多一个存储单元来存 '\0'
    char *result = (char *)malloc(sizeof(char)*(max_len + 1));
    substr(s, result, sub_i, sub_j+1);
    return result;
}