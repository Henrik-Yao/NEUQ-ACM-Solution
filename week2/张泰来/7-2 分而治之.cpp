#include <bits/stdc++.h>
using namespace std;
map <pair <int,int>,bool> maps;
vector <int> v[10005];
int n,m,k1,x,y,p,now;
int d[10005],covery[10005];
bool check[10005];
bool flag;
int main()
{
	scanf("%d%d",&n,&m);
	for (int i = 1;i <= m; i++)
	{
		scanf("%d%d",&x,&y);
		if (maps[make_pair(x,y)] == true) continue;
		maps[make_pair(x,y)] = true;
		maps[make_pair(y,x)] = true;
		v[x].push_back(y);
		v[y].push_back(x);
		d[x]++;
		d[y]++;
	}
	
	scanf("%d",&k1);
	for (int i = 1;i <= k1; i++)
	{
		memset(check,0,sizeof(check));
		memset(covery,0,sizeof(covery));
		flag = 1;
		scanf("%d",&p);
		for (int j = 1;j <= p; j++)
		{
			scanf("%d",&now);
			if (check[now]) continue;
			check[now] = true;
			for (int k = 0;k < v[now].size(); k++)
			{
				int next = v[now][k];
				covery[next]++;
			}
		}
		for (int j = 1;j <= n; j++)
		{
			if (check[j]) continue;
			if (covery[j] != d[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag) printf("YES\n");
		else printf("NO\n");
	}
	 return 0;
}
