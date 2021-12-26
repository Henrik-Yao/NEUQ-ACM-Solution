#include <bits/stdc++.h>
using namespace std;
struct node {
	int id,val;
	friend bool operator <(node x,node y)
	{
		return x.val > y.val;
	}
};
priority_queue <node> pq;
map <char,int> maps;
vector <int> v[155];
int depth[155],f[65];
int n,x,cnt,ans,m;
char c;
string s[65];
void dfs(int x)
{
	for (int i = 0;i < v[x].size(); i++)
	{
		int next = v[x][i];
		depth[next] = depth[x] + 1;
		dfs(next);
	}
	return;
}
int main()
{
	cin >> n;
	cnt = n;
	for (int i = 1;i <= n; i++)
	{
		cin >> c >> x;
		maps[c] = i;
		node a = {i,x};
		f[i] = x;
		pq.push(a);
	}
	while (pq.size() > 1)
	{
		node curx = pq.top();
		pq.pop();
		node cury = pq.top();
		pq.pop();
		int point = (++cnt);
		v[point].push_back(curx.id);
		v[point].push_back(cury.id);
		int val = curx.val + cury.val;
		node a = {point,val};
		pq.push(a);
	}
	dfs(cnt);
	for (int i = 1;i <= n; i++)
	{
		ans += f[i] * depth[i];
	}
	//cout << ans << endl;
	cin >> m;
	for (int i = 1;i <= m; i++)
	{
		int sum = 0;
		bool f1 = 1,f2 = 1;
		for (int j = 1;j <= n; j++)
		{
			cin >> c >> s[j];
			sum += s[j].size() * f[maps[c]];
		}
		if (sum != ans) f1 = 0;
		for (int j = 1;j <= n; j++)
		{
			for (int k = j + 1;k <= n; k++)
			{
				if (s[j].find(s[k]) == 0 || s[k].find(s[j]) == 0) 
			 	{
			 		f2 = 0;
			 		break;
				}
			}
		}
		if (f1 && f2) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
