#include<bits/stdc++.h>
using namespace std;
#define MAXN 310
#define MAXM 10010

int i,n,m,ans,sx,sy,sum;

struct info
{
	int u,v,c;
} a[MAXM];
bool cmp(info a,info b) { return a.c < b.c; }//分值的降序排序

class DisjointSet
{
	private :
		int fa[MAXN];//结点
	public :
		inline void init(int n)//初始化
		{
			int i;
			for (i = 1; i <= n; i++) fa[i] = i;
		}
		//并查集
		inline int get_root(int x)//找根
		{
			if (fa[x] == x) return x;
			fa[x] = get_root(fa[x]);
			return fa[x];
		}
		inline void merge(int x,int y)//合并
		{
			fa[get_root(x)] = get_root(y);
		}
} s;

int main()
{

	scanf("%d%d",&n,&m);
	for (i = 1; i <= m; i++) scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
	sort(a+1,a+m+1,cmp);
	s.init(n);
	for (i = 1; i <= m; i++)
	{
		sx = s.get_root(a[i].u);
		sy = s.get_root(a[i].v);
		if (sx != sy)
		{
			ans = a[i].c;
			if ((++sum) == n - 1) break;
			s.merge(a[i].u,a[i].v);
		}
	}

	printf("%d %d",n-1,ans);//最小生成树有n-1条边

	return 0;
}
