#include <iostream>

using namespace std;

typedef struct Node{
    Node *lchild;
    Node *rchild;
    int val;
}Node;

int n;
int state[110];

Node *insert(Node *T, int val){
    if(T == NULL){
        T = new Node;
        T->lchild = NULL;
        T->rchild = NULL;
        T->val = val;
        return T;
    }
    if(T->val > val){
        T->lchild = insert(T->lchild, val);
    }else if(T->val < val){
        T->rchild = insert(T->rchild, val);
    }
    return T;
}

void priorOrder(Node *T){
    if(T == NULL){
        return ;
    }
    cout << T->val << ' ';
    priorOrder(T->lchild);
    priorOrder(T->rchild);
}

void midOrder(Node *T){
    if(T == NULL){
        return ;
    }
    midOrder(T->lchild);
    cout << T->val << ' ';
    midOrder(T->rchild);
}

void postOrder(Node *T){
    if(T == NULL){
        return ;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout << T->val << ' ';
}

int main(){
    while(cin >> n){
        for(int i = 1; i <= n; i++){
        cin >> state[i];
        }
        Node *tree = new Node;
        tree->lchild = NULL;
        tree->rchild = NULL;
        tree->val = state[1];
        for(int i = 2; i <= n; i++){
            insert(tree, state[i]);
        }
        priorOrder(tree);
        cout << endl;
        midOrder(tree);
        cout << endl;
        postOrder(tree);
        cout << endl;
    }
    return 0;
}