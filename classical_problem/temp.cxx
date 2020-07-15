/*
    后缀表达式 (逆波兰式) 转前缀表达式 (波兰式)
*/
#include <iostream>
#include <string>
#include <stack>

using namespace std;

typedef struct Node{
    Node *l;
    Node *r;
    char val;
}Node;

void priorOrder(Node *root){
    if(root == NULL){
        return ;
    }
    priorOrder(root->l);
    cout << root->val << ' ';
    priorOrder(root->r);
}

bool ifNum(char temp){
    if(temp == '+' ||
       temp == '-' ||
       temp == 'x' ||
       temp == '/') return true;
    else return false;
}

Node *createNode(char val){
    Node *temp = new Node;
    temp->val = val;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

int main(){
    string pattern;
    stack<Node *> storage;
    Node *temp;
    cin >> pattern;
    for(int i = 0; i < pattern.size(); i++){
        if(ifNum(pattern[i])){
            cout << pattern[i] << endl;
            temp = createNode(pattern[i]);
            temp->r = storage.top(); storage.pop();
            temp->l = storage.top(); storage.pop();
            storage.push(temp);
        }else{
            temp = createNode(pattern[i]);
            storage.push(temp);
        }
    }
    Node *root = storage.top();
    cout << storage.size() << endl;
    priorOrder(root);
}