
#define MAX 50000

int contain(char *s, int len, char letter){
    for(int i = 0; i < len; i++){
        if(s[i] == letter){
            return 1;
        }
    }
    return 0;
}

int search(char *s, int start, int len, char letter){
    for(int i = start; i < len; i++){
        if(s[i] == letter){
            return i;
        }
    }
    return -1;
}

int lengthOfLongestSubstring(char * s){
    char sub[MAX] = {0};
    int index = 0;
    int result_index = 0;
    int sub_index = 0;
    int checkpoint = 0;
    while(s[index]){
        if(!contain(sub, sub_index, s[index])){
            sub[sub_index] = s[index];
            sub_index++;
            index++;
        }else{
            if(result_index < sub_index){
                result_index = sub_index;
            }
            checkpoint = search(s, checkpoint, index, s[index]) + 1;
            index = checkpoint;
            sub_index = 0;
        }
    }
    if(result_index < sub_index){
        result_index = sub_index;
    }
    return result_index;
}