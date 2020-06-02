
#define INT_MAX 2147483647
#define INT_MIN -2147483648

int myAtoi(char * str){
    int bit = 0;
    int index = 0;
    _Bool flag = 0;
    int Valuence = 1;
    double result = 0;
    while(str[index]){
        if(flag) if(str[index] < '0' || str[index] > '9') break;
        if(str[index] == ' ') {index++; continue;}
        if(str[index] == '-') {Valuence = -1; flag=1; index++; continue;}
        if(str[index] == '+') {Valuence = 1; flag=1; index++; continue;}
        if(str[index] >= '0' && str[index] <= '9'){
            flag = 1;
            result = result*10 + str[index] - '0';
            if(Valuence*result >= INT_MAX) return INT_MAX;
            if(Valuence*result <= INT_MIN) return INT_MIN;
            index++;
            continue;
        }
        return 0;
    }
    return Valuence*result;
}
