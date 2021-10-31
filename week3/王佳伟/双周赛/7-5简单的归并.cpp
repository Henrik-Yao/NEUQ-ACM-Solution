#include<bits/stdc++.h>
using namespace std;

int a[105];
int b[105];
int c[210];

int main() {
	int T, m, n;
	cin >> T;
	while(T--){
		cin >> m;
		for(int i = 0; i < m; i++){
			cin >> a[i];
		}
		cin >> n;
		for(int i = 0; i < n; i++){
			cin >> b[i];
		}
		//²¢
		int l = 0, r = 0, now = 0;
		while(l < m && r < n){
			if(a[l] <= b[r]){
				c[now++] = a[l++];
			}
			else{
				c[now++] = b[r++];
			}
		} 
		while(l < m){
			c[now++] = a[l++];
		}
		while(r < n){
			c[now++] = b[r++];
		}
		for(int i = 0; i < m+n; i++){
			cout << c[i];
			if(i != m+n-1){
				cout << " ";
				
			}
			else cout << endl;
		}
	} 
	
}
