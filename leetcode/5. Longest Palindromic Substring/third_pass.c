void substr(char *s, char *get, int start, int end){
    int index = 0;
    for(int i = start; i < end; i++){
        get[index++] = s[i];
    }
    get[index] = '\0';
}

char * longestPalindrome(char * s){
    if(s[0] == 0) return "";
    int index = 0;
    int i,j;
    int sub_i,sub_j;
    int max_len = 0;
    while(s[index]){
        j = i = index;
        while(i >= 0 && s[j]){
            if(s[i] == s[j]){
                if(max_len < j-i+1){
                    max_len = j - i + 1;
                    sub_i = i;
                    sub_j = j;
                }
            }else break;
            i--;
            j++;
        }
        index++;
    }
    index = 0;
    while(s[index]){
        i = index;
        j = index + 1;
        while(i >= 0 && s[j]){
            if(s[i] == s[j]){
                if(max_len < j-i+1){
                    max_len = j - i + 1;
                    sub_i = i;
                    sub_j = j;
                }
            }else break;
            
            i--;
            j++;
        }
        index++;
    }
    char *result = (char *)malloc(sizeof(char)*(max_len+1));
    substr(s, result, sub_i, sub_j+1);
    return result;
}
