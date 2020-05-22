#include <stdio.h>
#include <algorithm>
using namespace std;

int ifleap(int year){
    bool flag = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    if(flag) return 1;
    else return 0;
}

int dayOfMonth[13][2] = {
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

typedef struct Date{
    int year;
    int month;
    int day;
}Date;

Date convert(int date_int){
    Date temp;
    temp.day = date_int % 100;date_int /= 100;
    temp.month = date_int % 100;date_int /= 100;
    temp.year = date_int;

    return temp;
}

int flag[5001][13][32];

int main(){
    // memset(flag, 0, sizeof(int)*5001*13*32);
    int count = 0;
    for(int i = 0; i < 5001; i++){
        for(int j = 1; j < 13; j++){
            for(int k = 1; k < dayOfMonth[j][ifleap(i)] + 1; k++){
                flag[i][j][k] = count;
                count++;
            }
        }
    }

    int date1_int;Date date1;
    int date2_int;Date date2;
    while(scanf("%d %d", &date1_int, &date2_int) != EOF){
        date1 = convert(date1_int);
        date2 = convert(date2_int);
        printf("%d\n", flag[date2.year][date2.month][date2.day] - flag[date1.year][date1.month][date1.day] + 1);
    }
    return 0;
}