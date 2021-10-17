#include<bits/stdc++.h>
using namespace std;

int ans = 0;

void candy(int x) {
	ans++;
	if(x == 1) return;
	candy(1);
	for(int i = 2; i <= sqrt(x); i++){
		if(x % i == 0){
			if(x / i != i){
				candy(x/i);
			}
			candy(i);
		}
	}
}

int main() {
	int n;
	cin >> n;
	candy(n);
	cout << ans;
}
