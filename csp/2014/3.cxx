#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n;
int flag[129];
int ifcontain[129];
char buff[10000];
string pattern;
string ss[25];

vector<string> sort(vector<string> list_){
    for(int i = 0; i < list_.size(); i++){
        for(int j = i+1; j < list_.size(); j++){
            if(list_[i][1] > list_[j][1]){
                string temp;
                temp = list_[i];
                list_[i] = list_[j];
                list_[j] = temp;
            }
        }
    }
    return list_;
}

vector<string> process(string target){
    int s, e;
    s = 0; e = 0;
    vector<string> res;
    vector<string> sub_strings;
    memset(ifcontain, -1, sizeof(ifcontain));
    for(int j = 0; j <= target.size(); j++){
        if(target[j] == ' ' || target[j] == '\0'){
            s = e;
            e = j-1;
            string temp;
            temp.assign(target, s, e-s+1);
            sub_strings.push_back(temp);
            e = j+1;
        }
    }
    for(int i = 1; i < sub_strings.size(); i++){
        if(sub_strings[i][0] == '-'){
            if(flag[sub_strings[i][1]] == 0) return res;
            else if(flag[sub_strings[i][1]] == 1) {
                if(i+1 != sub_strings.size() && sub_strings[i+1][0] != '-') return res;
                if(ifcontain[sub_strings[i][1]] == -1){
                    res.push_back(sub_strings[i]);
                    ifcontain[sub_strings[i][1]] = res.size()-1;
                }
            }else if(flag[sub_strings[i][1]] == 2){
                if(i+1 == sub_strings.size() || sub_strings[i+1][0] == '-') return res;
                string temp = sub_strings[i] + ' ' + sub_strings[i+1];
                if(ifcontain[sub_strings[i][1]] != -1){
                    res[ifcontain[sub_strings[i][1]]] = temp;
                }else{
                    res.push_back(temp);
                    ifcontain[sub_strings[i][1]] = res.size()-1;
                }
                i++;
            }
        }
    }
    res = sort(res);
    return res;
}

int main(){
    memset(flag, 0, sizeof(flag));
    cin >> pattern;
    cin >> n;
    getchar();
    for(int i = 1; i <= n; i++){
        getline(cin, ss[i]);
    }
    // process pattern string
    for(int i = 0; i < pattern.size(); i++){
        if(pattern[i+1] == ':')
            flag[pattern[i]] = 2;
        else
            flag[pattern[i]] = 1;
    }
    vector<string> temp;
    for(int i = 1; i <= n; i++){
        temp = process(ss[i]);
        cout << "Case " << i << ":" << ' ';
        for(int j = 0; j < temp.size(); j++){
            cout << temp[j] << ' ';
        }
        cout << endl;
    }
    
}