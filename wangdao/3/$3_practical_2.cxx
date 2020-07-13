#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef struct Node{
    Node *lchild;
    Node *rchild;
    int val;
}Node;

int n, d;
int bl, br;
int state[1010];


int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> state[i];
    }
    cin >> d;
    bl = br = 1;
    for(int i = 1; i < d; i++){
        bl = bl * 2;
        br = br * 2 + 1;
    }
    for(int i = bl; i <= br; i++){
        cout << state[i] << ' ';
    }
    cout << endl;
}