



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 50000

int hash(int index){
    int r = index % MAX;
    return r < 0 ? r + MAX : r;
}

int* majorityElement(int* nums, int numsSize, int* returnSize){
    int *record = (int *)malloc(sizeof(int)*MAX);
    int count[MAX] = {0};
    int ok_num = 0;
    for(int i = 0; i < numsSize; i++){
        count[hash(nums[i])]++;
        if(count[hash(nums[i])] > numsSize/3){
            if(count[hash(nums[i])] <= (numsSize/3 + 1)){
                record[ok_num] = nums[i];
                ok_num++;   
            }
        }
    }
    *returnSize = ok_num;
    return record;
}
