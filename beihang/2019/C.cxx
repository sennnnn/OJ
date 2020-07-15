/*
    题目来源: http://www.noobdream.com/DreamJudge/Contest/45/1378/?Problem=C#
    日期: 2020 年 7 月 15 日
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string lower(string temp){
    for(int i = 0; i < temp.size(); i++){
        if(temp[i] >= 'A' && temp[i] <= 'Z') temp[i] -= 'A' - 'a';   
    }
    return temp;
}

int main(){
    int n;
    string strings[1010];
    string pattern;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> strings[i];
        }
        cin >> pattern;
        pattern = lower(pattern);
        for(int i = 1; i <= n; i++){
            int index = 0;
            int flag = 1;
            string temp = lower(strings[i]);
            for(int j = 0; j < pattern.size();){
                if(pattern[j] == '['){
                    // 处理 [] 中的模式字符串
                    int flag_sub = 0;
                    for(; pattern[j] != ']'; j++){
                        if(pattern[j] == temp[index]){
                            if(!flag_sub) index++;
                            flag_sub = 1;
                        }
                    }
                    j++;
                    if(flag_sub == 0) flag = 0;
                }else if(pattern[j++] != temp[index++]) flag = 0;
            }
            if(index != temp.size()) flag = 0;
            if(flag) cout << i << ' ' << strings[i] << endl;
        }
    }
}