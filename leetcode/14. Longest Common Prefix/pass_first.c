int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

void substr(char *s, char *get, int i, int j){
    int index = 0;
    for(int k = i; k < j; k++){
        get[index++] = s[k];
    }
    get[index] = 0;
}

char * longestCommonPrefix(char ** strs, int strsSize){
    int flag;
    int index = 0;
    if(strsSize == 0) return "";
    while(strs[0][index]){
        flag = 0;
        for(int j = 1; j < strsSize; j++){
            if(strs[j][index] != strs[0][index]) flag = 1;
        } 
        if(flag) break;
        index++;
    }
    char *result = (char *)malloc(sizeof(char)*(index+1));
    substr(strs[0], result, 0, index);
    return result;
}