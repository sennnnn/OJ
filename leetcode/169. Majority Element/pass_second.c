

int majorityElement(int* nums, int numsSize){
    int select = 0;
    int count = 0;
    for(int i = 0; i < numsSize; i++){
        if(nums[select] != nums[i]){
            count--;
            if(count < 0){
                select = i;
                count = 0;
            }
        }else{
            count++;    
        }
    }
    return nums[select];
}