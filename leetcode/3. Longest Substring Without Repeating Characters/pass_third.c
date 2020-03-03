int lengthOfLongestSubstring(char * s){
    int map[256] = {0};
    int index = 0;
    int start = 0;
    int result = 0;
    while(s[index]){
        if(map[s[index]] != 0){
            start = start > map[s[index]] ? start : map[s[index]];
        }
        result = result > (index - start + 1) ? result : index - start + 1;
        map[s[index]] = index + 1;
        index++;
    }
    return result;
}