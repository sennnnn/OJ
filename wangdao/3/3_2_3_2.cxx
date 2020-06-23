#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>

using namespace std;

char s[202];
int op_mat[][5] = {   // 编号 | 操作符号 | 说明
    {1, 0, 0, 0, 0},  // 0    | $       | 人为添加的操作符
    {1, 0, 0, 0, 0},  // 1    | +       | 加法
    {1, 0, 0, 0, 0},  // 2    | -       | 减法
    {1, 1, 1, 0, 0},  // 3    | *       | 乘法
    {1, 1, 1, 0, 0},  // 4    | /       | 除法
};

stack<int> op;
stack<double> num;

bool check_num(char temp){
    if(temp >= '0' && temp <= '9') return true;
    else return false;
}

bool check_op(char temp){
    if(temp == '+' || temp == '-' || temp == '*' || temp == '/') return true;
    else return false;
}


void getOpOrNum(bool &reto, int &retn, int &i){
    if(i == 0 && op.empty() == true){
        reto = true;
        retn = 0;
        return;
    }
    if(s[i] == 0){
        reto = true;
        retn = 0;
        return;
    }
    if(s[i] >= '0' && s[i] <= '9'){
        reto = false;
    }else{
        reto = true;
        if(s[i] == '+') retn = 1;
        if(s[i] == '-') retn = 2;
        if(s[i] == '*') retn = 3;
        if(s[i] == '/') retn = 4;
        i += 2;
        return;
    }
    retn = 0;
    for(;s[i] != ' ' && s[i] != 0; i++){
        retn *= 10;
        retn += s[i] - '0';
    }
    if(s[i] == ' ') i++;
    return;
}

int main(){
    int n;
    bool retop;
    int retnum,index;
    while(scanf("%[^\n]", s) != EOF){
        n = strlen(s);

        if(n == 1 && s[0] == '0') return 0;
        while(!op.empty()) op.pop();
        while(!num.empty()) num.pop();
        index = 0;
        while(true){
            getOpOrNum(retop, retnum, index);
            printf("%d %d %d \n", retop, retnum, index);
            if(index == 6) exit(0);
            if(retop == false){
                num.push(retnum);
            }else{
                double tmp;
                if(op.empty() == true || op_mat[retnum][op.top()] == 1){
                    op.push(retop);
                }else{
                    while(op_mat[retnum][op.top()] == 1){
                        int ret = op.top(); op.pop();
                        double b = num.top(); num.pop();
                        double a = num.top(); num.pop();
                        if(ret == 1) tmp = a + b;
                        if(ret == 2) tmp = a - b;
                        if(ret == 3) tmp = a * b;
                        if(ret == 4) tmp = a / b;
                        num.push(tmp);
                    }
                    op.push(retnum);
                }
                if(op.size() == 2 && op.top() == 0) break;
            }
        }

        printf("%.2f\n", num.top());
        break;
    }
    return 0;
}