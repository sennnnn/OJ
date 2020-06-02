# POJ

## 1001 高精度浮点运算

表面上直接字符转浮点，相乘，浮点转字符就完事了，实际上却是一道模拟题，我日，写了我一天, ACM 真是太变态了。  
由于自带的浮点数不能达到这么高的精度, 所以只好模拟竖式乘法 (即, 手算法) 然后一位一位以字符串的形式保存了。  
这道题对于输入的鲁棒性要求十分高，很恶心。我大致的思路是，首先对要乘数进行预处理，去掉小数点，去掉开头的零  
去掉结尾的零，(这里的意思是，例如，0001 要变成 1; 01.010 要变成 1.01; 0.0000 要变成 0)，并获取小数点后  
有多少位 (这里是为了方便后面计算的时候将小数变为整数计算) ，然后计算的时候就按位相乘进位那种手算法计算。  
然后通过后处理把小数点加上。

### 预处理

将被乘数按小数点拆成两段，分别处理，然后合并。  

``` c
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
```

### 计算

``` c
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
```

### 后处理

``` c
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
```