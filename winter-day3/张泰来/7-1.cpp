#include <bits/stdc++.h>
using namespace std;
int n,r,ans = -1e9,pos;
int a[105],depth[105],sum[105];
bool check[105];
void build(int x)
{
	r = max(r,x);
	if (!a[x]) return;
	if (!a[x + 1] && !a[x + 2])	check[x] = true;
	depth[x + 1] = depth[x] + 1;
	build(x + 1);
	depth[r + 1] = depth[x] + 1;
	build(r + 1);
	return;
}
int main()
{
	while (cin >> a[++n]);
	n--;
	build(1);
	
	for (int i = 0;i < n; i++)
	{
		sum[i] = -1e9;
	}
	
	for (int i = 1;i <= n; i++)
	{
		if (!check[i]) continue;
		if (sum[depth[i]] == -1e9) sum[depth[i]] = a[i];
		else sum[depth[i]] += a[i];
	}
	
	for (int i = 0;i < n; i++)
	{
		//cout << sum[i] << endl;
		if (sum[i] >= ans)
		{
			ans = sum[i];
			pos = i;
		}
	}
	cout << pos << endl;
	return 0; 
}
 
