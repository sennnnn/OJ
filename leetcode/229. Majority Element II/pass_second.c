
int* majorityElement(int* nums, int numsSize, int* returnSize){
    // 太巧妙了，大于 n/3 次的元素最多只能有两个。
    int count_1 = 0;
    int count_2 = 0;
    int select_1 = 0;
    int select_2 = 0;
    int ret_num = 0;
    int i;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == nums[select_1]){
            count_1++;
        }else if(nums[i] == nums[select_2]){
            count_2++;
        }else if(count_1 == 0){
            count_1++;
            select_1 = i;
        }else if(count_2 == 0){
            count_2++;
            select_2 = i;
        }else{
            count_1--;
            count_2--;
        }
    }
    count_1 = 0;
    count_2 = 0;
    for(i = 0; i < numsSize; i++){
        if(nums[i] == nums[select_1]) count_1++;
        else if(nums[i] == nums[select_2]) count_2++;
    }
    int *result = (int *)malloc(sizeof(int)*2);
    if(count_1 > numsSize/3) {result[ret_num++] = nums[select_1];}
    if(count_2 > numsSize/3) {result[ret_num++] = nums[select_2];}
    *returnSize = ret_num;
    return result;
}