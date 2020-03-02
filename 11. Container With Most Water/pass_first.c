
int min(int a, int b){
    return a < b ? a : b;
}

int maxArea(int* height, int heightSize){
    int max_contain = 0;
    int temp_contain = 0;
    for(int i = 0; i < heightSize; i++)
        for(int j = i+1; j < heightSize; j++){
            temp_contain = min(height[i], height[j]) * (j-i);
            max_contain = max_contain > temp_contain ? max_contain : temp_contain;
        }
    return max_contain;
}
