#include <stdio.h>
#include <stdlib.h>

// 优化之后的版本
int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

char * convert(char * s, int numRows){
    int s_length = len(s);
    int index = 0;
    char *result = (char *)malloc(sizeof(char)*(s_length+1));
    int col_len = numRows > 2 ? numRows+(numRows-2) : numRows;
    int col_num = (s_length-1)/col_len + 1;
    int col_in_index = 0;
    int col_index = 0;
    int flag = 0;
    int v_1 = 0;
    int v_2 = 0;
    while(s[index]){
        v_2 = -1;
        v_1 = col_in_index + col_index*col_len;

        if(v_1 < s_length){
            result[index++] = s[v_1];
            if(col_in_index != 0 && col_in_index != col_len/2) 
                v_2 = col_len - col_in_index + col_index*col_len;
            if(v_2 != -1 && v_2 < s_length){
                result[index++] = s[v_2];
            }
        }
        col_index++;
        if(col_index == col_num) {col_in_index++; col_index = 0;}
    }
    result[index] = '\0';
    return result;
}

int main(){
    char *s = "ABCDEFG";
    int numRows = 2;
    printf("%s\n", convert(s, numRows));
}