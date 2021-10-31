#include<bits/stdc++.h>
using namespace std;

int a[65];//3¸ù 
long long b[65];//4¸ù 

int main() {
	int n = 64; 
	
	for(int i = 1; i <= n; i++){
		a[i] = pow(2, i) - 1;
	}
	
	b[0] = 0;
	b[1] = 1;
	for(int i = 2; i <= n; i++){
		long long minm = INT_MAX;
		for(int j = i-1; j >= 1; j--){
			long long now = 2*b[j] + a[i-j];
			if(now >= minm) break;
			else minm = now;
		}
		b[i] = minm;
	}
//	for(int i = 1; i <= n; i++){
//		cout << b[i] << endl;
//	}
int m;
while(cin >> m){
	cout << b[m] << endl;
}
//cout << b[64];
}


