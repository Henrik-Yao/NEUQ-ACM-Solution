#include<bits/stdc++.h>
using namespace std;

int a[1000000];
int b[1000000];
int c[1000000];


int main() {
	int n; 
	cin >> n;
	unordered_map<int, int> ump1;
	unordered_map<int, int> ump2;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}	 
	
	ump1[a[0]]++;
	ump2[a[n-1]]++;
	b[0] = c[n-1] = 1;
	for(int i = 1; i < n; i++){
		ump1[a[i]]++;
		if(ump1[a[i]] > 1){
			b[i] = b[i-1];
		}
		else{
			b[i] = b[i-1] + 1;
		}
	}

	for(int i = n-2; i >= 0; i--){
		ump2[a[i]]++;
		if(ump2[a[i]] > 1){
			c[i] = c[i+1];
		}
		else{
			c[i] = c[i+1] + 1;
		}
	}
	
//	for(int i = 0; i < n; i++){
//		cout << b[i] ;
//	}
	
	int res = 1;
	for(int i = 0; i < n-1; i++){
		res = max(res, b[i]+c[i+1]);
	}
	cout << res;
}
