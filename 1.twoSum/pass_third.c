#include <stdio.h>

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