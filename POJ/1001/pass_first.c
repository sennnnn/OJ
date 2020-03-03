#include <stdio.h>
#include <stdlib.h>

// double str_to_double(char *s, int *flag){
//     int index = 0;
//     double temp_l = 0;
//     double temp_r = 0;
//     double right_meta = 0.1;
//     while(s[index] && s[index] != '.'){
//         temp_l = temp_l*10;
//         temp_l += s[index] - '0';
//         index++;
//         if(s[index] == '.') break;
//     }
//     if(s[index] == '.'){
//         index++;
//         while(s[index]){
//             temp_r += (s[index] - '0')*right_meta;
//             right_meta = right_meta/10;
//             index++;
//         }
//         *flag = 1;
//         return temp_l + temp_r;
//     }else {*flag = 0; return (int)temp_l;}
// }

// void substr(char *s, char *get, int i, int j){
//     int index = 0;
//     for(int k = i; k < j; k++){
//         s[k] = get[index++];
//     }
//     get[index] = 0;
// }

// void single_multiple(char *s, char m){
//     // 输入的应该是反序的即, 值为 12 输入为 "21"
//     // 为了节省内存进位就用 char 类型, 反正 carry 的范围就是 0~8;
//     char carry = 0;
//     int mid_res;
//     int index = 0;
//     int len_s = len(s);
//     char *temp = (char *)malloc(sizeof(len_s + 2));
//     memset(temp, 0, len_s+2);
//     while(s[index]){
//         mid_res = s[index]*m + carry;
//         temp[index] = mid_res%10;
//         carry = mid_res/10;
//         index++;
//     }
//     if(carry) temp[index++] = carry;
//     temp[index] = 0;
//     strcpy_cus(temp, s, index);
//     free(temp);
// }

// int pows(int m, int n){
//     if(n == 0) return 1;
//     int result = m;
//     for(int i = 0; i < n-1; i++){
//         result = result*m;
//     }
//     return result;
// }

int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

void strcpy_cus(char *s, char *d, int s_len){
    int index = 0;
    int len_s = len(s);
    while(index < s_len) {d[index] = s[index];index++;}
    d[index] = 0;
}

void reverse(char *s, int len){
    char temp;
    for(int i = 0; i < len/2; i++){
        temp = s[i];
        s[i] = s[len-1-i];
        s[len-i-1] = temp;
    }
}

int calculate(char *res, char *meta, int n){
    // meta 输入之后首先进行倒转，先仅对小数点左边考虑。
    // 假设已经倒转。
    if(n == 0) {res[0] = '1'; return 1;}
    else if(n == 1) {strcpy_cus(meta, res, len(meta)); return len(meta);}
    n = n-1;
    int carry;
    int index = 0;
    int temp = 0;
    char mid_res[100] = {0};
    int i,j;
    int len_meta = len(meta);
    int len_res = len_meta;
    for(int i = 0; i < len_meta; i++){
        meta[i] = meta[i] - '0';
    }
    reverse(meta, len_meta);
    strcpy_cus(meta, mid_res, len_meta);
    for(index = 0; index < n; index++){    
        for(i = 0; i < len_meta; i++){
            carry = 0;
            for(j = 0; j < len_res; j++){
                temp = meta[i] * mid_res[j] + carry;
                if(i == 0) res[i+j] = temp%10;
                else res[i+j] += temp%10;
                carry = temp/10 + (res[i+j])/10;
                res[i+j] = res[i+j]%10;
            }
            if(carry){res[i+j] = carry;}
        }
        len_res = i+j-1;
        if(carry) len_res++;
        strcpy_cus(res, mid_res, len_res);
    }
    for(int i = 0; i < len_res; i++){
        res[i] += '0';
    }
    reverse(res, len_res);
    return len_res;
}

int preprocess(char *s, char *get){
    int i = 0;
    int index = 0;
    int right_length = 0;
    int head_flag = 1;
    int flag = 0;
    char meta_l[7] = {0};
    char meta_r[7] = {0};
    int index_l = 0;
    int index_r = 0;
    // 去除小数点后的非法部分
    for(i = 0; i < len(s); i++){
        if(s[i] == '.') {flag = 1; continue;}
        if(flag) meta_r[index_r++] = s[i];
        else meta_l[index_l++] = s[i];
    }
    for(i = index_r - 1; i >= 0; i--){
        if(meta_r[i] != '0') break;
        meta_r[i] = 0;
    }
    for(i = 0; i < index_l; i++){
        if(meta_l[i] != '0') break;   
    }
    for(; i < index_l; i++){
        get[index++] = meta_l[i];
    }
    right_length = len(meta_r);
    for(i = 0; i < right_length; i++){
        get[index++] = meta_r[i];
    }
    get[index] = 0;
    return right_length;
}

void postprocess(char *s, char *get, int s_len, int right_length){
    int i = 0;
    int index = 0;
    int flag = 0;
    if(right_length > s_len){
        get[index++] = '.';
        for(i = 0; i < right_length - s_len; i++){
            get[index++] = '0';
        }
        for(i = 0; i < s_len; i++){
            get[index++] = s[i];
        }
        get[index] = 0;
    }else{
        for(; i < s_len; i++){
            if(index == s_len - right_length) get[index++] = '.';
            get[index++] = s[i];
        }
        get[index] = 0;
    }
}

void init(char *s, int len){
    for(int i = 0; i < len; i++){
        s[i] = 0;
    }
}

void main_process(char *s, char *end, int n, char *get, char *meta){
    int res_len;
    int right_length = 0;
    init(s, 100);
    right_length = preprocess(get, meta);
    if(len(meta) == 0) {printf("0\n"); return;}
    res_len = calculate(s, meta, n);
    right_length = right_length*n;
    postprocess(s, end, res_len, right_length);
    printf("%s\n", end);
}

int main(int argv, char **argc){
    int n;  //95.123 12
    char get[7];
    char *s = (char *)malloc(sizeof(char)*100);
    char *end = (char *)malloc(sizeof(char)*100);
    char meta[6];
    while(scanf("%s%d", get, &n) == 2){
        main_process(s, end, n, get, meta);
    }
}