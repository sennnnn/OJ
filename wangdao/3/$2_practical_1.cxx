#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n, a, b, sum;
    priority_queue<int, vector<int>, greater<int>> Q;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a;
        Q.push(a);
    }
    a = 0, b = 0, sum = 0;
    while(Q.size() != 1){
        a = Q.top();
        Q.pop();
        b = Q.top();
        Q.pop();
        sum += a + b;
        Q.push(a + b);
    }
    cout << sum << endl;
    return 0;
}