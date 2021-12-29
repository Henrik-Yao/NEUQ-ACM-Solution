#include<bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n, m;
int sum=0,sw=0;
int v[maxn] = {};
struct node
{
	int x, y, w;
};
bool cmp(node a, node b)
{
	return a.w < b.w;
}
int find(int a)
{
	if (v[a] == a) return a;
	return v[a]=find(v[a]);
}
void uni(int a, int b)//可能有点问题
{
	int fa = find(a); int fb = find(b);
	if (fa != fb) v[fa] = fb;
}
void solve(node t[])
{
	for (int i = 1; i <=m; i++)
	{
		if(find(t[i].x)!=find(t[i].y))
		{
			uni(t[i].x,t[i].y);
			sum++;
			sw+=t[i].w;
		}
		if(sum==n-1) break;
	}
	if(sum==n-1) cout<<sw<<endl;
	else cout<<"There is no minimum spanning tree."<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		node t[maxn];
		for (int i = 1; i <=m; i++)//初始化
		{
			v[i] = i;
		}
		for (int i = 1; i <= m; i++)//m行
		{
			scanf("%d%d%d", &t[i].x, &t[i].y, &t[i].w);
		}
		sort(t + 1, t + 1 + m, cmp);//从小到大排序
		sum=0,sw=0;
		solve(t);
	}
	return 0;
}