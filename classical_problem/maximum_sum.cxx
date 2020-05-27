#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

#define INF -999999999

// brute force 
int MaxSubSum_1(int list[], int n){
    int max = 0;
    int sum = 0;
    max = sum;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            sum = 0;
            for(int k = i; k <= j; k++){
                sum += list[k];
            }

            if(sum >= max) max = sum;
        }
    }
    return max;
}

// greedy
int MaxSubSum_2(int list[], int n){
    int sum = 0;
    int max = sum;
    for(int i = 0; i < n; i++){
        sum = 0;
        for(int j = i; j < n; j++){
            sum += list[j];
            if(sum > max) max = sum;
        }
    }
    return max;
}

// divide and conquer
int MaxSubSum_3(int list[], int left, int right){
    if(left == right){
        return list[left];
    }
    // printf("%d %d\n", left, right);
    int middle = (left + right)/2;
    int leftMaxSubSum = MaxSubSum_3(list, left, middle);
    int rightMaxSubSum = MaxSubSum_3(list, middle+1, right);
    int sum;

    int leftSideMaxSum = INF;
    sum = 0;
    for(int i = middle; i >= left; i--){
        sum += list[i];
        if(sum > leftSideMaxSum) leftSideMaxSum = sum;
    }

    int rightSideMaxSum = INF;
    sum = 0;
    for(int i = middle+1; i < right; i++){
        sum += list[i];
        if(sum > rightSideMaxSum) rightSideMaxSum = sum;
    }
    return max(max(leftMaxSubSum, rightMaxSubSum), leftSideMaxSum + rightSideMaxSum);
}

// dp
int MaxSubSum_4(int list[], int n){
    int max_so_far;
    int max_ending_here = max_so_far = list[0];
    for(int i = 1; i < n; i++){
        max_ending_here = max(list[i], max_ending_here + list[i]);
        max_so_far = max(max_so_far, max_ending_here);
    }

    return max_so_far;
}

int main(){
    int n;
    int list[100];
    int maxsubsum;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d", &list[i]);
        }
        maxsubsum = MaxSubSum_4(list, n);
        printf("%d\n", maxsubsum);
    }
}