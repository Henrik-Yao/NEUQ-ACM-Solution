#include<bits/stdc++.h>
using namespace std;
const int maxn = 2001;
int n,v,m;
int sum,sw,sv;//sw为成本，sv特殊城镇公路数
int f[maxn];
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
	if (f[a] == a) return a;
	return f[a]=find(f[a]);
}
bool uni(int x, int y)
{
	int a = find(x);
    int b = find(y);
    if (a != b) {
        f[b] = a;
        return 1;
    }
    return 0;
}
void solve(node t[])
{
	for (int i = 0; i <m; i++)
	{
		if((t[i].x==v||t[i].y==v)&&sv<2)
		{
			if(uni((t[i].x),t[i].y))
			{
				sv++;
				sum++;
				sw+=t[i].w;
			}
		}
		else if(t[i].x!=v&&t[i].y!=v)
		{
			if(uni((t[i].x),t[i].y))
			{
				sum++;
				sw+=t[i].w;
			}
		}
		if(sum==n-1) break;
	}
	if(sum==n-1&&sv<=2) printf("%d\n",sw);
	else printf("-1\n");
}
int main()
{
	while(cin>>n>>v>>m)
	{
		node t[maxn];
		for (int i = 0; i <m; i++)//初始化
		{
			f[i] = i;
		}
		for (int i = 0; i < m; i++)//m行
		{
			scanf("%d %d %d", &t[i].x, &t[i].y, &t[i].w);
		}
		sort(t , t  + m, cmp);//从小到大排序
		sum=0,sw=0,sv=0;
		solve(t);
	}
	return 0;
}