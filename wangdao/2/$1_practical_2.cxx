#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
struct stud{
    int number;
    int score;
    char name[101];
};
typedef struct stud stud;
bool cmp_1(stud a, stud b){
    // 学号
    return a.number < b.number;
}

bool cmp_2(stud a, stud b){
    // 姓名排序
    int temp = strcmp(a.name, b.name);
    if(temp == 0){
        return cmp_1(a, b);
    }else{
        return temp < 0;
    }
}

bool cmp_3(stud a, stud b){
    // 姓名排序
    if(a.score == b.score){
        return cmp_1(a, b);
    }else{
        return a.score < b.score;
    }
}

char *convert(int a){
    char *ret = (char*)malloc(sizeof(char)*6);
    memset(ret, '0', sizeof(char)*6);
    int index = 0;
    while(a != 0 || 6 - index > 0){
        ret[5-index] = '0' + a % 10;
        index++;
        a = a/10;
    }
    return ret;
}

int main(){
    int n;
    int c;
    stud buf[1000];
    while(scanf("%d %d", &n, &c) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d %s %d", &buf[i].number, buf[i].name, &buf[i].score);
        }
        if(n == 0) break;
        if(c == 1){
            sort(buf, buf+n, cmp_1);
        }else if(c == 2){
            sort(buf, buf+n, cmp_2);
        }else if(c == 3){
            sort(buf, buf+n, cmp_3);
        }
        printf("Case:\n");
        for(int i = 0; i < n; i++){
            printf("%s %s %d\n", convert(buf[i].number), buf[i].name, buf[i].score);
        }
    }
    return 0;
}