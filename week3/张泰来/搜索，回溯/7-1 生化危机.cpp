#include <bits/stdc++.h>
using namespace std;
vector <int> v[1000005];
int m,n,k,s,d,x,y,t;
int city[55],fa[1000005];
bool safe[1000005];
int find(int x)
{
	if (x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}
void unionn(int x,int y)
{
	int a = find(x);
	int b = find(y);
	if (a == b) return;
	fa[a] = b;
	return;
}
int main()
{
	scanf("%d%d%d",&m,&n,&k);
	for (int i = 0;i <= m; i++)
		fa[i] = i;
	for (int i = 1;i <= n; i++)
	{
		scanf("%d",city + i);
		safe[city[i]] = true;
	}
	for (int i = 1;i <= k; i++)
	{
		scanf("%d%d",&x,&y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	scanf("%d%d",&s,&d);
	if (!safe[d])
	{
		printf("The city %d is not safe!\n",d);
		return 0;
	}
	safe[s] = true;
	for (int i = 1;i <= n; i++)
	{
		for (int j = 0;j < v[city[i]].size(); j++)
		{
			int next = v[city[i]][j];
			if (!safe[next]) continue;
			unionn(city[i],next);
		}
	}
	if (find(s) == find(d))
	{
		printf("The city %d can arrive safely!\n",d);
	} else{
		printf("The city %d can not arrive safely!\n",d);
	}
	return 0;
}

