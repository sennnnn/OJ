#include <stdio.h>
#include <stdlib.h>
int ifleap(int year){
    bool flag = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(flag) return 1;
    else return 0;
}

int dayOfMonth[13][32] = {
    {0, 0},
    {31, 31},
    {28, 29},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31},
    {31, 31},
    {30, 30},
    {31, 31},
    {30, 30},
    {31, 31}
};

int *parse_day_month(int count, int year){
    int index = 1;
    int *day_month = (int *)malloc(sizeof(int)*2);
    int flag = ifleap(year);
    while(count > dayOfMonth[index][flag]){
        count = count - dayOfMonth[index][flag];
        index++;
    }
    day_month[1] = count;day_month[0] = index;
    
    return day_month;
}

int main(){
    int year;
    int count;
    int *result;
    while(scanf("%d %d", &year, &count) != EOF){
        result = parse_day_month(count, year);
        printf("%d-%02d-%02d\n", year, result[0], result[1]);
    }
    return 0;
}