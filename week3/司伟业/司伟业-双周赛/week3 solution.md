# 7-1 最大子段和

考虑贪心，如果一个子段和为负，那么这一个子段对后面的子段就不会有贡献，直接舍去，如果为正，那么后面的子段加上这个子段一定更优，所以只需从前往后扫一遍，累加答案，如果累加值为负，就将其清零，取累加过程中的最大值即可。时间复杂度O（n）。~~也不知道为啥数据范围才1e4~~n^2暴力都能过……

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

int n,ans,aa,tot;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		aa=read();
		tot=tot+aa;
		if(tot<0) tot=0;
		ans=max(ans,tot);
	}
	cout<<ans;
	return 0;
}

~~~

# 7-2 汉诺塔问题 

作业原题，递归求解即可。

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 100005
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

int n; 
char c[5][maxn];

void F(int n,int from,int to)
{
	if(n==1)
	{
		printf("%s->%s\n",c[from],c[to]);
		return;
	}
	F(n-1,from,6-from-to);
	F(1,from,to);
	F(n-1,6-from-to,to);
}

int main()
{
	n=read();
	for(int i=1;i<=3;i++) cin>>c[i];
	F(n,1,3);
	return 0;
}
~~~

# 7-3 汉诺塔III 

设移动i个盘的答案为f[i]，则:
$$
f_i=f_{i-1}*3+2~~(f_1=2)
$$
递推求解即可。

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

long long aa,ans;

int main()
{
	while(~scanf("%d",&aa))
	{
		ans=0;
		for(int i=1;i<=aa;i++)
		{
			ans=ans*3+2;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

~~~

# 7-4 汉诺塔II 

由于不知道怎么样拆解才能取得最优解，于是我决定采取DP来做此题，设f<sub>i</sub>表示移动i个盘的最小次数，有
$$
f_i=min\{f_{i-j}*2+2^j-1\}~~(0<j<i)
$$

~~~cpp
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 1005
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

int n,aa; 
long long f[maxn];

long long qpow(long long a,int b)
{
	long long ans=1;
	while(b)
	{
		if(b&1) ans=ans*a;
		a=a*a;
		b>>=1;
	}
	return ans;
}

signed main()
{
	memset(f,0x3f,sizeof(f));
	f[1]=1;
	for(int i=2;i<=100;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(qpow(2,j)>=f[i]) break;
			f[i]=min(f[i],f[i-j]*2+qpow(2,j)-1);
		}
	}
	while(~scanf("%d",&aa))
	{
		cout<<f[aa]<<endl;
	}
	return 0;
}

~~~

# 7-5 简单的归并 

开两个指针，分别指向两个序列的首个数字，依次比较取最小即可

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define maxn 105
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

int t,n,m,l1,l2;
int a[maxn],b[maxn],c[maxn<<1];

int main()
{
	t=read();
	while(t--)
	{
		n=read();
		for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
		m=read();
		for(int i=1;i<=m;i++)
		scanf("%d",&b[i]);
		int l1=1;l2=1;
		for(int i=1;i<=n+m;i++)
		{
			if(l1>n)
			{
				c[i]=b[l2];l2++;
			}
			else if(l2>m)
			{
				c[i]=a[l1];l1++;
			}
			else if(a[l1]>=b[l2])
			{
				c[i]=b[l2];l2++;
			}
			else if(a[l1]<b[l2])
			{
				c[i]=a[l1];l1++;
			}
			if(i==1) printf("%d",c[i]);
			else printf(" %d",c[i]);
		}
		puts("");
	}
	return 0;
}
~~~

# 7-6 字符串的全排列 

经典递归全排列，只需要每次取数后打一个标记，放回时标记清楚即可。

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

char c[10];
int a[50],b[50],num,vis[50];

void dfs(int x)
{
	if(x==num+1)
	{
		printf("%s\n",c+1);
		return;
	}
	for(int i=1;i<=num;i++)
	{
		if(vis[i]) continue;
		vis[i]=1;c[x]=b[i]+'a'-1;
		dfs(x+1);
		vis[i]=0;
	}
}

int main()
{
	cin>>(c+1);
	int l=strlen(c+1);
	for(int i=1;i<=l;i++)
	{
		a[c[i]-'a'+1]=1;
	}
	for(int i=1;i<=26;i++)
	{
		if(a[i]) b[++num]=i;
	}
	dfs(1);
}
~~~

# 7-7 逆序对 

经典问题逆序对，一般采用归并排序和树状数组两种解法，我讲一下树状数组做法，首先对序列离散化，说白了就是sort+unique+lower_bound，然后开一个树状数组，每次将树状数组中以此数为下标的位置加1，然后将此数以后的位置加和累加入答案。时间复杂度O（nlogn）

~~~c++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long
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

int n,a[maxn],c[maxn],b[maxn],ans;

int lowbit(int x)
{
	return x&(-x);
}

void add(int x,int a)
{
	for(int i=x;i<=n;i+=lowbit(i))
	{
		c[i]=c[i]+a;
	}
}

int ask(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}

signed main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		b[i]=a[i];
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
	{
		a[i]=lower_bound(b+1,b+1+n,a[i])-b;
	}
	for(int i=1;i<=n;i++)
	{
		ans+=ask(n)-ask(a[i]);
		add(a[i],1);
	}
	cout<<ans;
	return 0;
}
~~~

# 7-8 二分查找 

不清楚这题的意义何在，查一个数需要二分？扫一遍不就行了吗？建议将题目改为输出n此查找的位置。

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

int n,m;
int a[maxn];

int main()
{
	n=read();m=read();int l=1,r=n;
	for(int i=1;i<=n;i++)
	a[i]=read();
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(a[mid]>=m)
		{
			r=mid-1;
		}
		else l=mid+1;
	}
	cout<<l;
	return 0;
}
~~~



