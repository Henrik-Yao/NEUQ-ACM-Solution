#include <bits/stdc++.h>
using namespace std;
int a[10009], g[10006];
vector<int>b[1005];
int main()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	int q;
	for(int i = 1; i <= n; i++)
	{
		int k = 1;
		while(k <= ans && g[k] < a[i]) k++;
		g[k] = a[i]; b[k].push_back(a[i]);
		if(a[i] == 1) q = k;
		if(k > ans) ans++;
	}
	for (int i = 0; i < b[q].size(); i++) 
	{
		cout << b[q][i];
		if(i < b[q].size()-1) cout << " ";
		else cout << endl;
	}
	cout << ans;
	return 0;
}
