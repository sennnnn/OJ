#include <stdio.h>
#include <string.h>
#include <stack>

using namespace std;

int main(){
    char s[101];
    char out[101];
    int n;
    int temp;
    stack<int> index;
    stack<char> storage;
    while(scanf("%s", s) != EOF){
        n = strlen(s);
        memset(out, ' ', sizeof(out));
        out[n] = '\0';
        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
                storage.push(s[i]);
                index.push(i);
            }else if(s[i] == ')'){
                if(storage.empty()){
                    out[i] = '?';
                }else{
                    if(storage.top() == '('){
                        storage.pop();     
                        index.pop();   
                    }else{
                        out[i] = '?';
                    }
                }
            }else if(s[i] == ']'){
                if(storage.empty()){
                    out[i] = '?';
                }else{
                    if(storage.top() == '['){
                        storage.pop();     
                        index.pop();   
                    }else{
                        out[i] = '?';
                    }
                }
            }else if(s[i] == '}'){
                if(storage.empty()){
                    out[i] = '?';
                }else{
                    if(storage.top() == '{'){
                        storage.pop();     
                        index.pop();   
                    }else{
                        out[i] = '?';
                    }
                }
            }
        }
        if(!index.empty()){
            while(!index.empty())
            {
                temp = index.top();
                index.pop();
                out[temp] = '$';
            }
        }
        printf("%s\n", out);
    }
}