#include <stdio.h>

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

// 没通过, 主要是没考虑负数
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int min = 2147483647;
    for(int i = 0; i < numsSize; i++){
        if(min > nums[i]){
            min = nums[i];
        }
    }
    int len = target - min + 1;
    int* hash_table = (int *)malloc(sizeof(int)*len);
    int* result = (int *)malloc(sizeof(int)*2);
    if(hash_table == NULL || result == NULL){
        *returnSize = 0;
        return NULL;
    }
    for(int i = 0; i < len; i++){
        hash_table[i] = -1;
    }
    for(int i = 0; i < numsSize; i++){
        if(nums[i] < len){
            hash_table[nums[i]] = i;
        }
    }
    for(int i = 0; i < numsSize; i++){
        if(target - nums[i] < len && target - nums[i] >= 0){
            result[0] = i;
            result[1] = hash_table[target-nums[i]];
            if(result[0] == result[1] || result[1] == -1) continue;
            *returnSize = 2;
            return result;
        }
    }
    *returnSize = 0;
    return NULL;
}

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
