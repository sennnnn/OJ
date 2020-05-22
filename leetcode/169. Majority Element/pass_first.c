

#define MAX 50000

int hash(int index){
    int r = index % MAX;
    return r < 0 ? r + MAX : r;
}

int majorityElement(int* nums, int numsSize){
    int map[MAX] = {0};
    int temp = 0;
    for(int i = 0; i < numsSize; i++){
        map[hash(nums[i])]++;
        if(map[hash(nums[i])] > numsSize/2) temp = nums[i];
    }
    return temp;
}

