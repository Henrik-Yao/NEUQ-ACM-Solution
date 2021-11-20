#include <bits/stdc++.h>
using namespace std;

int n, a[50009];
bool v[50009], ans = 0;

void dfs(int s) {
	if(!a[s]) 
	{
		ans = 1;
		return;
	}
	v[s] = 1;
	int l = s - a[s], r = s + a[s];
	if(l >= 0 && !v[l]) dfs(l);
	if(r < n && !v[r]) dfs(r); 
}

int main (){
	int s;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	cin >> s;
	dfs(s);
	if(ans) cout << "True";
	else cout << "False";
	return 0;
}
