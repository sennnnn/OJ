int len(char *s){
    int index = 0;
    while(s[index]) index++;
    return index;
}

int romanToInt(char * s){
    int result = 0;
    int s_length = len(s);
    int index = 0;
    for(; s[index] == 'M'; index++) result += 1000;
    if(index + 1 < s_length)
        if(s[index] == 'C' && s[index + 1] == 'M'){
            result += 900;index += 2;}
    for(; s[index] == 'D'; index++) result += 500;
    if(index + 1 < s_length)
        if(s[index] == 'C' && s[index + 1] == 'D'){
            result += 400;index += 2;}
    for(; s[index] == 'C'; index++) result += 100;
    if(index + 1 < s_length)
        if(s[index] == 'X' && s[index + 1] == 'C'){
            result += 90;index += 2;}
    for(; s[index] == 'L'; index++) result += 50;
    if(index + 1 < s_length)
        if(s[index] == 'X' && s[index + 1] == 'L'){
            result += 40;index += 2;}
    for(; s[index] == 'X'; index++) result += 10;
    if(index + 1 < s_length)
        if(s[index] == 'I' && s[index + 1] == 'X'){
            result += 9;index += 2;}
    for(; s[index] == 'V'; index++) result += 5;
    if(index + 1 < s_length)
        if(s[index] == 'I' && s[index + 1] == 'V'){
            result += 4;index += 2;}
    for(; s[index] == 'I'; index++) result += 1;
    return result;
}

