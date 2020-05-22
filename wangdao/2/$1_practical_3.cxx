#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

bool cmp(char a, char b){
    return a < b;
}

int main(){
    char buf[201];
    memset(buf, 0, sizeof(char)*201);
    while(scanf("%s", buf) != EOF){
        sort(buf, buf+strlen(buf), cmp);
        printf("%s\n", buf);
        memset(buf, 0, sizeof(char)*201);
    }
    return 0;
}