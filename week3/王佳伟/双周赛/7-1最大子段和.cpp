#include<bits/stdc++.h>
using namespace std;


int a[10005];
int maxm = 0;
int main() {
	int n;
	cin >> n; 
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		a[i] = max(a[i-1] + a[i], max(a[i], 0));
		maxm = max(a[i], maxm);
	}
	cout << maxm;
}
