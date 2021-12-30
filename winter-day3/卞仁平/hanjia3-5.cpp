#include<bits/stdc++.h>
using namespace std;
#define MAXN 310
#define MAXM 10000
 
int i,n,m,ans,sx,sy,sum;
 
struct info
{
	int u,v,c;
}a[MAXM];
bool cmp(info a,info b) 
{ return a.c < b.c; }
 
class DisjointSet
{
	private :
		int fa[MAXN];
	public :
		inline void init(int n)
		{
			int i;
			for(i=1;i<=n;i++)fa[i]=i;
		}
		inline int get_root(int x)
		{
			if(fa[x]==x)return x;
			fa[x]=get_root(fa[x]);
			return fa[x];
		}
		inline void merge(int x,int y)
		{
			fa[get_root(x)]=get_root(y);	
		}	
}s;
 
int main()
{
	cin>>n>>m;
	for(i=1;i<=m;i++) 
    scanf("%d%d%d",&a[i].u,&a[i].v,&a[i].c);
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
	

    cout<<n-1<<" "<<ans<<endl;
	return 0;
}