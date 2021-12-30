#include <bits/stdc++.h>
using namespace std;

int n;
int a[10006];
bool vis[10006];

int main()
{
	int ans = 0;
	int n;	cin >> n;
	for (int i = 1; i <= n; i++)	cin >> a[i], vis[a[i]] = 1;
	for (int i = 0; i <= 10000; i++) if(vis[i] && vis[i+1]) ans++;
	cout << ans;
	
	return 0;
}
