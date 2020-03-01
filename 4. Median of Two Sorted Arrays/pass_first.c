double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int odevity_flag = (nums1Size + nums2Size)%2;
    int median_index = (nums1Size + nums2Size)/2 + odevity_flag;
    int i = 0, j = 0;
    int index = 0;
    int last = 0;
    int middle = 0;
    while(i < nums1Size && j < nums2Size){
        if(index > median_index) break;
        if(nums1[i] < nums2[j]) {last = middle; middle = nums1[i]; i++;}
        else {last = middle; middle = nums2[j]; j++;}
        index++;
    }
    while(i < nums1Size){
        if(index > median_index) break;
        last = middle; middle = nums1[i];
        i++;
        index++;
    }
    while(j < nums2Size){
        if(index > median_index) break;
        last = middle; middle = nums2[j];
        j++;
        index++;
    }
    if(odevity_flag){
        return median_index == 1 ? middle : last;
    }else{
        return (last+middle)/2.0;
    }
}