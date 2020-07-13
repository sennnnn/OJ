#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

typedef struct Node{
    int val;
    int num;
}Node;

typedef struct cmp{
    bool operator()(Node a, Node b){
        return a.val > b.val;
    }
}cmp;

int main(){
    priority_queue<int, vector<int>, greater<int>> abc;
    int N;
    int state[1010];
    int a, b, sum;
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> state[i];
        abc.push(state[i]);
    }
    a = 0, b = 0, sum = 0;
    while(abc.size() != 1){
        a = abc.top();
        abc.pop();
        b = abc.top();
        abc.pop();
        sum += a + b;
        abc.push(a + b);
    }
    cout << sum << endl;
    return 0;
}