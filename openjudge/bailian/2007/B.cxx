/*
    题目名字: 单词替换
    编号: 1946
    日期: 2020 年 7 月 7 日
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main(){
    int len, s, e, w_i;
    char s_r[110];
    string ss[110];
    string replace, get;
    cin.getline(s_r, 110);
    getline(cin, replace);
    getline(cin, get);
    len = strlen(s_r);
    s = 0; e = 0; w_i = 0;
    for(int i = 0; i < len; i++){
        if(s_r[i] == ' '){
            s = e;
            e = i-1;
            ss[w_i++].assign(s_r, s, e-s+1);
            e = i+1;
        }else if(s_r[i+1] == '\0'){
            s = e;
            e = i;
            ss[w_i++].assign(s_r, s, e-s+1);
        }
    }
    for(int i = 0; i < w_i; i++){
        if(ss[i].compare(replace) == 0){
            ss[i] = get;
        }
    }
    for(int i = 0; i < w_i; i++){
        cout << ss[i] << ' ';
    }
    cout << endl;
}