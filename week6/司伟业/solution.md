# 7-1 字符串模式匹配（KMP）

KMP模板题

### 代码：

```C++
#include<iostream>
#include<string>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<map>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#define maxn 1000005
using namespace std;

inline int read()
{
	int x=1,res=0;
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

char a[maxn],b[maxn];
int p[maxn];
int m,n,ans;

void pre()
{
	p[1]=0;
	int j=0;
	for(int i=1;i<m;i++)
	{
		while(j>0&&b[i+1]!=b[j+1])
		{
			j=p[j];
		}
		if(b[i+1]==b[j+1]) 
		{
			j++;
		}
		p[i+1]=j;
	}
}

void kmp()
{
	int j=0;
	for(int i=0;i<n;i++)
	{
		while(j>0&&b[j+1]!=a[i+1])
		{
			j=p[j];
		}
		if(b[j+1]==a[i+1])
		j++;
		if(j==m)
		{
			ans++;
		    j=p[j];
		}
	}
}

int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	pre();
	kmp();
	cout<<ans;
	return 0;
}
```

## 7-2 妈妈再也不用担心我被拖库啦！

根据题意求密码的hash值，再用map判断密码是否合法

### 代码：

```C++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
#include<queue>
#include<map>
#include<cmath>
#define maxn 2000005
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
	int vis,hash;
	string key;
};
int n,part[10];
char opt;
string name,key;
map<string,node>q;

int main()
{
	n=read();
	for(int i=1;i<=n;i++)
	{
		cin>>opt;
		if(opt=='R')//resign
		{
			cin>>name>>key;
			if(q[name].vis==1) puts("Repeated!");
			else
			{
				q[name].key=key;
				puts("Signed!");
				q[name].vis=1;
				int lenth=key.size();
				for(int j=0;j<lenth;j++)
					if(key[j]>='A'&&key[j]<='Z')
					key[j]+=32;
				for(int j=1;j<=4;j++) part[j]=lenth/4;
				for(int j=1;j<=(lenth%4);j++) part[j]++;
				int u=0,ans=0;
				for(int j=1;j<=4;j++)
				{
					int num=0;
					for(int l=0;l<part[j];l++,u++)
					{
						if(key[u]>='0'&&key[u]<='9') num+=key[u]-'0';
						else num+=key[u]-'a'+10;
					}
					ans+=(num%36)*(int)pow(36,4-j);
				}
				q[name].hash=ans;
			}
		}
		if(opt=='L')//log in
		{
			cin>>name>>key;string aaa=key;
			int lenth=key.size();
			for(int j=0;j<lenth;j++)
				if(key[j]>='A'&&key[j]<='Z')
				key[j]+=32;
			for(int j=1;j<=4;j++) part[j]=lenth/4;
			for(int j=1;j<=(lenth%4);j++) part[j]++;
			int u=0,ans=0;
			for(int j=1;j<=4;j++)
			{
				int num=0;
				for(int l=0;l<part[j];l++,u++)
				{
					if(key[u]>='0'&&key[u]<='9') num+=key[u]-'0';
					else num+=key[u]-'a'+10;
				}
				ans+=(num%36)*(int)pow(36,4-j);
			}
			if(q[name].vis==1&&q[name].key==aaa) puts("Success!");
			else if(q[name].vis==1&&q[name].key!=key&&q[name].hash==ans) puts("Attention!");
			else puts("Failed!");
		}
	}
	return 0;
}
```



## 7-3 子字符串个数匹配

用cin.get()输入，hash比较包含关系即可

### 代码：

```C++
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define mod 2000000007
#define maxn 2000006
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

char aa[maxn];
int s[1002][100002],cnt,c[100002],has,qpow[maxn],ans;

int main()
{
	cin.get(aa,maxn);
	int len=strlen(aa);
	for(int i=0;i<len;i++)
	{
		if( (aa[i]<'a'||aa[i]>'z')&&(aa[i]<'A'||aa[i]>'Z') ) continue;
		cnt++;
		int num=0;
		for(;;)
		{
			if( (aa[i]>='A'&&aa[i]<='Z') ) aa[i]+=32;
			num++;
			s[cnt][num]=(s[cnt][num-1]*26+aa[i]-'a')%mod;
			if( (aa[i+1]<'a'||aa[i+1]>'z')&&(aa[i+1]<'A'||aa[i+1]>'Z') ) break;
			i++;
		}
		c[cnt]=num;
	}
	cin>>aa;len=strlen(aa);
	qpow[0]=1;
	for(int i=0;i<len;i++)
	{
		if( (aa[i]>='A'&&aa[i]<='Z') ) aa[i]+=32;
		has=(has*26+aa[i]-'a')%mod;
	}
	for(int i=1;i<=500005;i++)
	qpow[i]=(qpow[i-1]*26)%mod;
	for(int i=1;i<=cnt;i++)
	{
		int pd=0;
		for(int l=1;l<=c[i]-len+1;l++)
		{
			int r=l+len-1;
			if( ( (s[i][r]-s[i][l-1]*qpow[r-l+1]%mod)%mod+mod)%mod==has)
			{
				pd=1;
				break;
			}
		}
		if(pd==1) ans++;
	}
	cout<<ans;
	return 0;
}
```

