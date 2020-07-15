/*
    题目名字: ISBN 号码
    日期: 2020 年 7 月 14 日
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    string temp;
    cin >> temp;
    int sum = 0;
    char raw = temp[temp.size()-1];
    int base = 1;
    for(int i = 0; i < temp.size()-1; i++){
        if(temp[i] == '-') continue;
        sum += (temp[i] - '0') * (base);
        base++;
    }
    if(sum % 11 == 10) {
        if(raw == 'X')
            cout << "Right" << endl;
        else{
            temp[temp.size()-1] = 'X';
            cout << temp << endl;
        }
    }else if(sum % 11 == raw - '0') {
        cout << "Right" << endl;
    }else{
        temp[temp.size()-1] = sum % 11 + '0';
        cout << temp << endl;
    }
}