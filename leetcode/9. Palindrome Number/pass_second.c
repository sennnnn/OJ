
#define bool _Bool
#define true 1
#define false 0

bool isPalindrome(int x){

    if(x == 0) return true;
    if(x < 0 || x%10 == 0) return false;
    int temp = 0;
    int index = 0;
    while(x > temp){
        temp= x%10 + temp*10;
        x = x/10;
    }
    return temp == x || temp/10 == x;
}