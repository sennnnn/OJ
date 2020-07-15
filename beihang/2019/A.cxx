#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

bool ifPrime(int num){
	if(num == 1) return false;
	for(int i = 2; i <= sqrt(num); i++){
		if(num % i == 0) return false;
	}
	return true;
}

int main(){
	int flag;
	int n;
	while(cin >> n){
		vector<int> temp;
		flag = 0;
		for(int i = 2; i <= n; i++){
			if(ifPrime(i)){
				if(i % 10 == 1){
					temp.push_back(i);
					flag = 1;
				}
			}
		}
		if(flag == 0) cout << -1 << endl;
		else {
			for(int i = 0; i < temp.size()-1; i++){
				cout << temp[i] << ' ';
			}
			cout << temp[temp.size()-1] << endl;
		}
	}
	return 0;
}