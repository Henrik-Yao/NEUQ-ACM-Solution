#include<bits/stdc++.h>
using namespace std;

int ans = 0;


int main() {
	int n, T;
	int res = INT_MIN;
	cin >> n >> T;
	int t, v;
	for(int i = 0; i < n; i++){
		cin >> v >> t;
		if(t <= T)
		res = max(res, v);
		else res = max(res, v-t+T);
	}
	cout << res;
}
