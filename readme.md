# 记录

## 两数之和

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