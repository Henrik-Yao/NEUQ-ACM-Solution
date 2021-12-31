# 7-1 求解区间覆盖问题 

先将区间有小到大排序，然后计算相邻两区间之间的距离，再将两区间距离排序，取最小的n-m个距离即可，然后再加上每段区间的长度及n。即：
$$
ans=\sum^{n-m}_{i=1}s_i+n
$$

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

int n,m,a[maxn],s[maxn],ans;

bool cmp(int a,int b)
{
	return a>b;
}

int main()
{
	n=read();m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	for(int i=1;i<n;i++) s[i]=a[i+1]-a[i];
	sort(s+1,s+n,cmp);
	for(int i=m;i<n;i++) ans+=s[i]-1;
	ans+=n;
	cout<<ans;
	return 0;
}
~~~

# 7-2 铺满方格 

简单递推，注意开longlong
$$
f_i=\begin{cases}
1~~~~~~({i}{=}{=}{1})\\
2~~~~~~({i}{=}{=}{2})\\
4~~~~~~({i}{=}{=}{3})\\
{f_{i-1}+f_{i-1}+f_{i-3}}~~~~~~(i\geq{4})\\
\end{cases}
$$

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10005
#define int long long
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

int f[maxn],n;

signed main()
{
	f[1]=1;f[2]=2;f[3]=4;
	for(int i=4;i<=50;i++)
	f[i]=f[i-3]+f[i-2]+f[i-1];
	while(cin>>n)
	{
		cout<<f[n]<<endl;
	}
}

~~~

