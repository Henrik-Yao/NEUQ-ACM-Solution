#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#define int long long 
#define maxn 100555
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

int cnt,len,ans[maxn];
string a,b[maxn];

signed main()
{
	cin>>a;
	len=a.size();
	for(int i=0;i<len;i++)
	{
		if(cnt==0&&a[i]!='[') cout<<a[i];
		else if(a[i]=='[')
		{
			cnt++;
			if(a[i+1]>='0'&&a[i+1]<='9'&&a[i+2]>='0'&&a[i+2]<='9')
			{
				ans[cnt]=(a[i+1]-'0')*10+a[i+2]-'0';
				i++;
			}
			else ans[cnt]=(a[i+1]-'0');
			i++;
		}
		else if(a[i]==']')
		{
			cnt--;
			while(ans[cnt+1]--)
			{
				b[cnt]=b[cnt]+b[cnt+1];
			}
			b[cnt+1].clear();
			if(cnt==0)
			{
				cout<<b[0];
				b[0].clear();
			}
		}
		else if(cnt!=0)
		{
			b[cnt]=b[cnt]+a[i];
		}
	}
	return 0;
}

