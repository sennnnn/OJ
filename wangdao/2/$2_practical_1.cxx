#include <stdio.h>

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

int collect_last(int month, int year){
    int temp = 0;
    for(int i = 1; i < month; i++){
        temp += dayOfMonth[i][ifleap(year)];
    }
    return temp;
}

int main(){
    int year,month,day;
    while(scanf("%d %d %d", &year, &month, &day) != EOF){
        printf("%d\n", day + collect_last(month, year));
    }
}