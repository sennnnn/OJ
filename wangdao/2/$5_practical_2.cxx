#include <stdio.h>
#include <algorithm>

using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int elements[100];

int search(int start, int end, int val){
    if(elements[start] == val){
        return start;
    }else if(start >= end) return -1;

    int middle = (start+end)/2;
    
    if(val <= elements[middle])
        return search(start, middle, val);
    else
        return search(middle+1, end, val);
}

int main(){
    int n,m;
    int query;
    while(scanf("%d", &n) != EOF){
        getchar();
        for(int i = 0; i < n; i++){
            scanf("%d", &elements[i]);
        }
        getchar();
        scanf("%d", &m);
        getchar();
        for(int i = 0; i < m; i++){
            scanf("%d", &query);
            sort(elements, elements+n, cmp);
            if(search(0, n, query) != -1) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}