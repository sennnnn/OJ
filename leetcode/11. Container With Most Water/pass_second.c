
int min(int a, int b){
    return a < b ? a : b;
}

int max(int a, int b){
    return a > b ? a : b;
}

int maxArea(int* height, int heightSize){
    int max_contain = 0;
    int temp_contain = 0;
    int i = 0, j = heightSize - 1;
    while(j > i){
        max_contain = max(max_contain, min(height[i], height[j])*(j-i));
        if(height[i] < height[j]) i++;
        else j--;
    }
    return max_contain;
}