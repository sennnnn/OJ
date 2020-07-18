/*
    题目名字: 程序运行时调用栈分析
    日期: 2020 年 7 月 16 日
    状态: 考试时未完成
*/
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>

using namespace std;

int op_flag;
string func_name;
vector<string> func_stack;
vector<vector<string>> res;
map<string, int> string_flag;
map<string, int>::iterator string_iter;
set<string> string_set;
set<string>::iterator string_set_iter;
set<string> string_sub_set[210];
int used_flag[210];


int main(){
    memset(used_flag, 0, sizeof(used_flag));
    int string_num = 0;
    while(cin >> op_flag){
        if(op_flag == 1){
            cin >> func_name;
            func_stack.push_back(func_name);
            if(string_set.find(func_name) == string_set.end()){
                string_flag.insert(pair<string, int>(func_name, string_num));
                string_num++;
                used_flag[string_flag[func_name]]++;
            }else{
                used_flag[string_flag[func_name]]++;
            }
            string_set.insert(func_name);
        }else{
            func_stack.pop_back();
        }
        res.push_back(func_stack);
        for(int i = func_stack.size()-1; i > 0; i--){
            string_sub_set[string_flag[func_stack[i]]].insert(func_stack[i-1]);
        }
        if(func_stack.size() == 0) break;
    }
    int max_size = 0;
    for(int i = 0; i < res.size(); i++){
        if(max_size < res[i].size()) max_size = res[i].size();
    }
    if(max_size == 0) return 0;
    for(int i = 0; i < res.size(); i++){
        if(res[i].size() == max_size){
            string temp = res[i][res[i].size()-1];
            cout << temp << ' ';
            for(int j = 0; j < res[i].size(); j++){
                cout << res[i][j];
                if(j != res[i].size() - 1) cout << '-';
            }
            cout << ' ' << string_sub_set[string_flag[temp]].size() << ' ' << used_flag[string_flag[temp]];
            cout << endl;
        }
    }
}