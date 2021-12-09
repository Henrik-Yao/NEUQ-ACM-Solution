# 7-1 最少失约 

将每段时间按左端点为第一关键字，右端点为第二关键字升序排序，每次判断下一次活动时间是否晚于上一次结束时间，并更新右端点即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

struct node
{
	int l,r;
}a[maxn];
int t,n,ans;
bool cmp(node a,node b)
{
	if(a.l==b.l) return a.r<b.r;
	else return a.l<b.l;
}

int main()
{
	t=read();
	while(t--)
	{
		n=read();ans=0;
		for(int i=1;i<=n;i++)
		{
			a[i].l=read();
			a[i].r=read();
		}
		sort(a+1,a+1+n,cmp);
		int last=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i].l>=last) last=a[i].r;
			else
			{
				last=min(last,a[i].r);
				ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
~~~

# 7-2 跳一跳 

每次选当前能跳到的点中a<sub>i</sub>+i中最大的点即可

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1000005
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

int n,a[maxn],vis[maxn];
int main()
{
//	freopen("111.out","r",stdin);
	n=read();int cnt=0;
	for(int i=1;i<=n;i++){
		a[i]=read();a[i]+=i;
	}
	int m=1,k;
	for(int i=m;i<n;i=k)
	{
		cnt++;if(a[i]>=n) break;
		for(int j=i+1;j<=a[i];j++)
		{
			if(a[j]>m)
			{
				m=a[j];
				k=j;
			}
		}
	}
	cout<<cnt;
	return 0;
}
~~~

