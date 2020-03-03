# 记录

## 两数之和

主要有几类测试用例应该考虑:  
1. 第一种 [3,2,4] 6 要考虑到 result[0] != result[1]
2. 第二种 [-3,2,3,6] 0 要考虑这种正负数交替的
3. 第三种 [-1,-2,-3,-4,-5] -8 这种纯负数的

### 第一种方法 暴力搜索法

这个就不解释了, 就是直接双重遍历:

``` c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    // 之前主要是没有理解 returnSize 这个量是用来干嘛的, 这是直接最简单的暴力搜索的方法啦, 唉没办法咯, 只能想到这个。
    for(int i = 0; i < numsSize; i++)
    {
        for(int j = i + 1; j < numsSize; j++)
        {
            if(nums[i] == target - nums[j])
            {
                int* a = (int *)malloc(sizeof(int) * 2);
                if(a == NULL)
                {
                    *returnSize = 0;
                    return NULL;
                }
                a[0] = i;
                a[1] = j;
                *returnSize = 2;
                return a;
            }
        }
    }
    *returnSize = 0;
    return NULL;
}
```

>需要注意的是 returnSize 也得赋值, 而且在无答案的时候要返回 NULL;  

### 第二种解法 哈希表法

即将 nums 里面的元素映射到一个哈希表里面, 通过输入 nums 的元素值而直接返回其在 nums 中的下标,  
这里细节就是我们创建一个 50000 长度的哈希表并默认全部初始化为 0, 然后通过求余运算将 nums 中的  
元素放缩到 0~50000 之间, 并将其下标加 1, 则哈希表中的某个元素为 0, 则说明该元素不对应 nums 里  
的元素, 于是我们遍历 nums, 当 target 减去 nums 中的元素得到的值在哈希表中的映射不为 0 时, 则  
说明其是得到的值也是 nums 中的元素, 而其对应的哈希表映射就是其在 nums 中的下标。

``` c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 50000

int hash(int key){
    // 用求余来实现 hash 算法, 可以很好地处理负数
    int r = key % MAX;
    // 倘若 nums 中存在比 SIZE 更大的情况, 只好这样处理
    return r < 0 ? r + MAX : r;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int map[MAX] = {0};
    for(int i = 0; i < numsSize; i++){
        map[hash(nums[i])] = i+1;
    }
    for(int i = 0; i < numsSize; i++){
        int temp = map[hash(target-nums[i])];
        if(temp != 0){
            temp = temp - 1;
            if(i == temp) continue;
            int* result = (int *)malloc(sizeof(int) * 2);
            result[0] = i;
            result[1] = temp;
            *returnSize = 2;
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
}
```

### 第三种解法, 一轮哈希表法

考虑到输出时顺序可以反过来, 那么就可以一遍判断一边赋值哈希表。

``` c
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 50000

int hash(int key){
    // 用求余来实现 hash 算法, 可以很好地处理负数
    int r = key % MAX;
    // 倘若 nums 中存在比 SIZE 更大的情况, 只好这样处理
    return r < 0 ? r + MAX : r;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int map[MAX] = {0};
    for(int i = 0; i < numsSize; i++){
        int temp = map[hash(target-nums[i])];
        if(temp != 0){
            temp = temp - 1;
            if(i == temp) continue;
            int* result = (int *)malloc(sizeof(int) * 2);
            result[0] = i;
            result[1] = temp;
            *returnSize = 2;
            return result;
        }
        map[hash(nums[i])] = i+1;
    }
    *returnSize = 0;
    return NULL;
}
```

## 最长回文子串

### 第四种解法 Manacher algorithm

主要的思路就是通过使用回文串的性质来减少重复搜索, 首先通过插入 # , 强行将所有的字符串都整成奇数长度, 而且这样一操作  
所有的回文串都将是奇数长度的, 奇数长度的回文串则一定有一个中心, 这就方便了下一步的计算, 为了充分利用回文串的性质减少  
重复搜索, 要定义一个半径数组, r[], 这个半径数组存储的就是以某个位置为中心的回文串的 (总长度+1)/2, 根据这个半径数组  
当已经确定 r[0,...,i-1] 时, 能够得到一个 c 以及 r[c], c + r[c] 是最大的, 这时根据回文串的性质, 若 i 落在以 r[c] 为  
半径, c 为中心的范围内, 即 i < c+r[c], 那么就确定以 i 为中心的回文串半径至少应该是 c+r[c]-i+1 或者是 r[2*c-i], 注意  
是至少是, 如果 i >= c+r[c], 则以 i 为中心的回文串半径至少应该是 1, 知道了以 i 为中心的回文串半径至少应该是多少之后  
那么在从这个最小半径开始向外扩搜索, 直到不满足回文串条件, 当然了获得 r[i] 之后应该要检查, i+r[i] 是否比 c+r[c] 更大,  
以达到更新 c 的目的, 实际上这一种解法就是外扩搜索法的优化版, 能够通过利用回文串的性质来让你避开已经搜索过的结果。 

``` c
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

void preprocess(char *s ,char *ss ,int s_length){
    int index = 0;
    for(int i = 0; i < s_length; i++){
        ss[index++] = '#';
        ss[index++] = s[i];
    }
    ss[index++] = '#';
    ss[index] = '\0';
}

int min(int a, int b){
    return a < b ? a : b;
}

char *longestPalindrome(char * s){
    int s_length = len(s);
    if(s_length == 0) return "";
    char *ss = (char *)malloc(sizeof(char)*(2*s_length+2));
    int r[2*s_length+1];
    preprocess(s, ss, s_length);
    int mx = 1;
    int c = 0;
    r[0] = 1;
    int max_len = 0;
    int sub_i = 0,sub_j = 0;
    for(int i = 1; i < 2*s_length+1; i++){
        if(i < mx) r[i] = min(mx-i+1, r[2*c-i]);
        else{
            r[i] = 1;
        }
        while(i - r[i] >= 0 && i + r[i] < 2*s_length+1 && ss[i-r[i]] == ss[i+r[i]]) r[i]++; 
        if(r[i] + i - i > c){
            c = i;
            mx = i + r[i] - 1;
        }
        if(r[i] - 1 > max_len){
            sub_i = i - r[i] + 1;
            sub_j = i + r[i] - 1;
            max_len = r[i] - 1;
        }
    }
    sub_i = sub_i/2;
    sub_j = sub_j/2 - 1;
    char *result = (char *)malloc(sizeof(char)*(max_len+1));
    substr(s, result, sub_i, sub_j+1);
    return result;
}
```