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
