# 7-1 素数 

暴力判断素数即可，不过每行结尾不能有多余空格

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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

int a,b,num=1; 

int main()
{
	while(cin>>a>>b)
	{
		int cnt=0;
		for(int i=a;i<=b;i++)
		{
			int pd=0;
			for(int j=2;j*j<=i;j++)
			{
				if(i%j==0) pd=1;
			}
			if(pd==0&&cnt==0){
				cout<<i;cnt++;
			}
			else if(pd==0) printf(" %d",i);
		}
		cout<<endl;
	}
	return 0;
}
~~~

# 7-2 炒鸡楼梯 

递推即可，注意F[1]=0

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10555
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

long long f[maxn];
int n,aa;

int main()
{
	f[1]=1;f[2]=1;
	for(int i=3;i<=500;i++)
	f[i]=f[i-2]+f[i-1];
	f[1]=0;
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		cout<<f[aa]<<endl; 
	}
	return 0;
}
~~~

# 7-3 求素数个数 

埃筛

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 10000005
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

int n,vis[maxn],ans;

int main()
{
	n=read();
	for(int i=2;i<=n;i++)
	{
		if(vis[i]) continue;
		ans++;
		if((long long)i*i<=n)
		for(int j=i*i;j<=n;j+=i)
		{
			vis[j]=1;
		}
	}
	cout<<ans;
	return 0;
}
~~~

# 7-4 幂次取余 

快速幂取模

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
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

int t,a,b,mod;

int qpow(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1) ans=(ans*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return ans;
}

signed main()
{
	t=read();
	while(t--)
	{
		a=read();b=read();mod=read();
		cout<<qpow(a,b)<<endl;
	}
	return 0;
}

~~~

