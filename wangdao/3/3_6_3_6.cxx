#include <iostream>
#include <cstring>

using namespace std;

typedef struct Node{
    Node *lchild;
    Node *rchild;
    char val;
}Node;

int n, index_;
int l1, l2, flag;
char get1[12], get2[12];
char *str;
char s1[12], s2[12];

void priorOrder(Node *T){
    if(T == NULL){
        return ;
    }
    str[index_++] = T->val;
    priorOrder(T->lchild);
    priorOrder(T->rchild);
}

void midOrder(Node *T){
    if(T == NULL){
        return ;
    }
    midOrder(T->lchild);
    str[index_++] = T->val;
    midOrder(T->rchild);
}

void postOrder(Node *T){
    if(T == NULL){
        return ;
    }
    postOrder(T->lchild);
    postOrder(T->rchild);
    str[index_++] = T->val;
}

Node *insert(Node *T, char val){
    if(T == NULL){
        T = new Node;
        T->lchild = NULL;
        T->rchild = NULL;
        T->val = val;
        return T;
    }
    if(val < T->val){
        T->lchild = insert(T->lchild, val);
    }else if(val > T->val){
        T->rchild = insert(T->rchild, val);
    }
    return T;
}

Node *create(char *s, Node *root){
    int l = strlen(s);
    root = new Node;
    root->val = s[0];
    root->lchild = NULL;
    root->rchild = NULL;
    for(int i = 1; i < l; i++){
        insert(root, s[i]);
    }
    return root;
}

int main(){
    while(cin >> n){
        if(n == 0) break;
        memset(get1, 0, sizeof(get1)); memset(get2, 0, sizeof(get2));
        cin >> get1;
        Node *root;
        root = create(get1, root);
        for(int i = 1; i <= n; i++){
            flag = 0;
            cin >> get2;
            Node *sub;
            sub = create(get2, sub);
            memset(s1, 0, sizeof(s1)); memset(s2, 0, sizeof(s2));
            index_ = 0;
            str = s1;
            priorOrder(root);
            index_ = 0;
            str = s2;
            priorOrder(sub);
            if(strcmp(s1, s2) == 0) flag++;
            memset(s1, 0, sizeof(s1)); memset(s2, 0, sizeof(s2));
            index_ = 0;
            str = s1;
            midOrder(root);
            index_ = 0;
            str = s2;
            midOrder(sub);
            if(strcmp(s1, s2) == 0) flag++;
            if(flag == 2) cout << "YES" << endl;
            else cout << "NO" << endl;
        }
    }
    return 0;
}