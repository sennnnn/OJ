#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct Node{
    Node* lchild;
    Node* rchild;
    char c;
}Node;

char s1[30];
char s2[30];
int l1, l2;

Node *create(){
    Node *temp = new Node();
    temp->lchild = NULL;
    temp->rchild = NULL;
    return temp;
}

Node *build(int x1, int y1, int x2, int y2){
    Node *T = create();
    T->c = s1[x1];
    int rootidx;
    for(int i = x2; i <= y2; i++){
        if(s2[i] == s1[x1]) {rootidx = i; break;}
    }
    if(rootidx != x2){
        T->lchild = build(x1+1, x1+(rootidx-x2), x2, rootidx-1);
    }
    if(rootidx != y2){
        T->rchild = build(x1+(rootidx-x2)+1, y1, rootidx+1, y2);
    }
    return T;
}

void postOrder(Node *T){
    if(T == NULL){
        return ;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    cout << T->c;
    return ;
}

int main(){
    while(1){
        if(!(cin >> s1) || !(cin >> s2)) break;
        l1 = strlen(s1);
        l2 = strlen(s2);
        Node *T = build(0, l1-1, 0, l2-1);
        postOrder(T);
        cout << endl;
        memset(s1, 0, sizeof(s1));
        memset(s2, 0, sizeof(s2));
    }
    return 0;
}