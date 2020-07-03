/*
    题目名字: 单词排序
    题目编号: 6249
    日期: 2020 年 6 月 29 日
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int num;
    string words[110];
    while(cin >> words[num]){
        bool has = false;
        for(int i = 0; i < num; i++){
            if(words[i].compare(words[num]) == 0){
                has = true;
                break;
            }
        }
        if(!has) num++;
    }
    sort(words, words+num);
    for(int i = 0; i < num; i++){
        cout << words[i] << endl;
    }
    return 0;
}


    