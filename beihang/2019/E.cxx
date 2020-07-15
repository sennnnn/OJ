/*
    题目来源: http://www.noobdream.com/DreamJudge/Issue/page/1492/#
    日期: 2020 年 7 月 15 日
*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct Node{
    Node* sub1;
    Node* sub2;
    Node* sub3;
    int val;
}Node;

typedef struct leaf{
    int val;
    int prior;
}leaf;

int n, m;
int state[10010][5];
leaf leaves[10010];
vector<vector<int>> res;
vector<int> path;

bool cmp(leaf a, leaf b){
    return a.prior < b.prior;
}

Node* create(int val){
    Node *temp = new Node;
    temp->val = val; temp->sub1 = NULL; temp->sub2 = NULL; temp->sub3 = NULL;
    return temp;
}

void build(Node* root){
    int i;
    int flag = 1;
    for(i = 1; i <= n; i++){
        if(state[i][1] == root->val) {
            flag = 0;
            break;
        }
    }
    if(flag) return ;
    if(state[i][2] != -1){
        root->sub1 = new Node;
        root->sub1->val = state[i][2]; root->sub1->sub1 = NULL; root->sub1->sub2 = NULL; root->sub1->sub3 = NULL;
        build(root->sub1);
    }else return;
    
    if(state[i][3] != -1){
        root->sub2 = new Node;
        root->sub2->val = state[i][3]; root->sub2->sub1 = NULL; root->sub2->sub2 = NULL; root->sub2->sub3 = NULL;
        build(root->sub2);
    }else return;

    if(state[i][4] != -1){
        root->sub3 = new Node;
        root->sub3->val = state[i][4]; root->sub3->sub1 = NULL; root->sub3->sub2 = NULL; root->sub3->sub3 = NULL;
        build(root->sub3);
    }else return;
}

void search(Node* root, int val){
    if(root->val == val){
        res.push_back(path);
        return ;
    }
    path.push_back(root->val);
    if(root->sub1 != NULL){
        search(root->sub1, val);
    }

    if(root->sub2 != NULL){
        search(root->sub2, val);
    }

    if(root->sub3 != NULL){
        search(root->sub3, val);
    }
    path.pop_back();
}

int main(){
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> state[i][1] >> state[i][2] >> state[i][3] >> state[i][4];
        }
        Node *root = new Node;
        root->val = state[1][1]; root->sub1 = NULL; root->sub2 = NULL; root->sub3 = NULL;
        build(root);
        cin >> m;
        for(int i = 1; i <= m; i++){
            cin >> leaves[i].val >> leaves[i].prior;
        }
        sort(leaves+1, leaves+m+1, cmp);
        for(int i = 1; i <= m; i++){
            search(root, leaves[i].val);
        }
        for(int i = 0; i < res.size(); i++){
            if(i == 0){
                for(int j = 0; j < res[i].size(); j++){
                    cout << res[i][j] << ' ';
                }
            }
            if(i != 0){
                int same = 0;
                for(int j = 0; j < res[i-1].size() && j < res[i].size(); j++){
                    if(res[i-1][j] != res[i][j]) {same = j-1; break;}
                }
                for(int j = res[i-1].size()-1; j >= same; j--){
                    cout << res[i-1][j] << ' ';
                }
                for(int j = same+1; j < res[i].size(); j++){
                    cout << res[i][j] << ' ';
                }
            }
            cout << leaves[i+1].val << endl;
            if(i == res.size() - 1){
                for(int j = res[i].size()-1; j >= 0; j--){
                    cout << res[i][j] << ' ';
                }
                cout << endl;
            }
        }
    }
}