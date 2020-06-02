#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

typedef struct person{
    char number[20];
    char name[20];
    char male[20];
    int age;
}person;

void print_record(person p){
    printf("%s %s %s %d\n", p.number, p.name, p.male, p.age);
}

bool cmp(person a, person b){
    bool temp = strcmp(a.number, b.number) < 0;
    return temp;
}

int search(person *list, char *key, int n){
    int low = 0;int high = n-1;
    int middle,temp;
    while(low <= high){
        middle = (low + high)/2;
        temp = strcmp(key, list[middle].number);
        if(temp == 0) return middle;
        if(temp < 0) high = middle - 1;
        else low = middle + 1;
    }
    return -1;
}

int main(){
    int n;
    int m;
    char key[20];
    int result;
    person ps[1000];
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%s %s %s %d", ps[i].number, ps[i].name, ps[i].male, &ps[i].age);
        }
        sort(ps, ps+n, cmp);
        // for(int i = 0; i < n; i++){
        //     print_record(ps[i]);
        // }
        // exit(0);
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%s", &key);
            result = search(ps, key, n);
            if(result != -1)
                print_record(ps[result]);
            else{
                printf("No Answer!\n");
            }
        }
    }
}