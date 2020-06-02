#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char haab[20][10] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

char Tzolkin[21][10] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", 
    "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int haab_days = 365;
int Tzolkin_days = 260;

int month_index(char *month){
    for(int i = 0; i < 20; i++){
        if(strcmp(month, haab[i]) == 0) return i;
    }
    return 0;
}

void do_(char *month_name, int year, int day){
    int count;
    int month;
    month = month_index(month_name);
    count = year*haab_days + month*20 + day;
    year = count/Tzolkin_days;
    count = count - year*Tzolkin_days;
    month = count%20;
    day = count%13 + 1;
    printf("%d %s %d\n", day, Tzolkin[month], year);
}

int main(){
    int n;
    int count,month_count;
    int day,year,month;
    char month_name[10];
    while(scanf("%d", &n) != EOF){
        printf("%d\n", n);
        for(int i = 0; i < n; i++){
            scanf("%d. %s %d", &day, month_name, &year);
            do_(month_name, year, day);
        }
    }
}