#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+9;
vector<int>G[N];
bool v[N], g[N];
int ans;

int str(string a)
{
	if(a == "-1") return 0;
	int ans = 0, k = 1;
	for (int i = a.size()-1; i >= 0; i--)
	{
		ans += (a[i]-'0') * k;
		k *= 10;
	}
	return ans;
}

void dfs(int n, bool j, int k)
{
	if(k == 5) return;
	if(j)
	{
		v[n] = 1;
		for(auto y : G[n])
			dfs(y, j, k+1);
	}
	else
	{
		if(v[n])
		{
			ans = 0;
			return;
		}
		else for (auto y : G[n])
				dfs(y, j, k+1);
	}
}

int main ()
{
	int n, k;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		string a, c, d;
		char b;
		cin >> a >> b >> c >> d;
		int n1 = str(a), nf = str(c), nm = str(d);
		if(b == 'M') g[n1] = 1;
		else g[n1] = 0;
		g[nf] = 1, g[nm] = 0;
		if(nf) G[n1].push_back(nf);
		if(nm) G[n1].push_back(nm);
	}
	cin >> k;
	while(k--)
	{
		string a, b;
		cin >> a >> b;
		int n1 = str(a), n2 = str(b);
		if(g[n1] == g[n2]) 
		{
			cout << "Never Mind" << endl;
			continue;
		}
		memset(v, 0, sizeof(v));
		ans = 1;
		dfs(n1, 1, 0);
		dfs(n2, 0, 0);
		if(ans) cout << "Yes";
		else cout << "No";
        if(k) cout << endl;
	}
	return 0;
}

















