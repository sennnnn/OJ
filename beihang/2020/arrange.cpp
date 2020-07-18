/*
    题目名字: 整数排列
    日期: 2020 年 7 月 16 日
    状态: 考试时候通过样例
*/

#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct Node{
    Node* l;
    Node* r;
    int val;
}Node;

int n;
int state[110];
int mid;
queue<Node*> Node_queue;

bool cmp(int a, int b){
    return a < b;
}

void midOrder(Node* root){
    if(root == NULL){
        return ;
    }
    midOrder(root->l);
    cout << root->val << ' ';
    midOrder(root->r);
}

Node* create(int val){
    Node* temp = new Node;
    temp->val = val;
    temp->l = NULL;
    temp->r = NULL;
    return temp;
}

Node* sortTreeBuild(Node *root, int val){
    if(root == NULL){
        Node* temp = create(val);
        return temp;
    }
    if(val <= root->val){
        root->l = sortTreeBuild(root->l, val);
    }else{
        root->r = sortTreeBuild(root->r, val);
    }
    return root;
}

Node* build(int s, int e){
    if(s == e){
        return create(state[s]);
    }
    int len = e-s+1;
    int up = 1, und = 3;
    while(!(up <= len && und >= len)){
        up = 2*up + 1;
        und = 2*und + 1;
    }
    Node* root;
    if(len <= (up+und)/2) {
        root = create(state[e-(up-1)/2]);
        if(e-(up-1)/2-1 >= s) root->l = build(s, e-(up-1)/2-1);
        if(e-(up-1)/2+1 <= e) root->r = build(e-(up-1)/2+1, e);
    }else {
        root = create(state[s+(und-1)/2]);
        if(s+(und-1)/2-1 >= s) root->l = build(s, s+(und-1)/2-1);
        if(s+(und-1)/2+1 <= e) root->r = build(s+(und-1)/2+1, e);
    }
    return root;
}

void levelOrder(Node* root){
    if(root == NULL){
        return ;
    }else{
        Node_queue.push(root);
    }
    while(!Node_queue.empty()){
        Node* temp = Node_queue.front();
        Node_queue.pop();
        cout << temp->val << ' ';
        if(temp->l != NULL){
            Node_queue.push(temp->l);
        }
        if(temp->r != NULL){
            Node_queue.push(temp->r);
        }
    }
}

int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> state[i];
    }
    sort(state+1, state+1+n, cmp);
    if(n == 1) cout << state[1] << endl;
    else{
        Node *root = build(1, n);
        levelOrder(root);
        cout << endl;
    }  
    return 0;
}