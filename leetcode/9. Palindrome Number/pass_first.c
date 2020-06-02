
#define bool _Bool
#define true 1
#define false 0

bool isPalindrome(int x){
    // max 2147483647
    if(x == 0) return true;
    char *temp = (char *)malloc(sizeof(char)*11);
    int index = 0;
    if(x < 0) temp[index++] = '-';
    while(x){
        temp[index++] = x%10 + '0';
        x = x/10;
    }
    for(int i = 0; i < index/2; i++){
        if(temp[i] != temp[index - (i+1)]) return false;
    }
    return true;
}

