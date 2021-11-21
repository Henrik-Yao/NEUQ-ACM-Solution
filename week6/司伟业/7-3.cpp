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
