#include <stdio.h>
#include <string.h>

typedef struct Date{
    int year;
    int month;
    int day;
}Date;

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

int flag[5001][13][32];

char month[13][100] = {"", "January", "February", "March", "Apirl", "May", 
                       "June", "July", "August", "September", "October", "November", "December"};

char dayOfWeek[8][100] = {"", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int month_convert(char* month_string){
    for(int i = 1; i < 13; i++){
        if(strcmp(month_string, month[i]) == 0) return i;
    }
    return 0;
}

int main(){
    int count = 0;
    for(int i = 0; i < 5001; i++){
        for(int j = 1; j < 13; j++){
            for(int k = 1; k < dayOfMonth[j][ifleap(i)] + 1; k++){
                flag[i][j][k] = count;
                count++;
            }
        }
    }
    int day;
    char month[100];
    int year;
    while(scanf("%d %s %d", &day, month, &year) != EOF){
        int month_int = month_convert(month);
        int target_datestamp = flag[year][month_int][day];
        int start_datestamp = flag[2020][5][22]; // 星期五
        int residual_error = target_datestamp - start_datestamp;
        int whatday = 5;
        if(residual_error < 0){
            residual_error = (-residual_error)%7;
            whatday = whatday - residual_error;
            whatday = whatday < 0?whatday + 7:whatday;
        }else{
            residual_error = residual_error%7;
            whatday = whatday + residual_error;
            whatday = whatday > 7?whatday - 7:whatday;
        }
        printf("%s\n", dayOfWeek[whatday]);    
    }
    return 0;
}