#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define maxn 1000005
using namespace std;

int read()
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

string a;

signed main()
{
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
	{
		if(a[i]=='B')
		printf("tsaedsae");
		else if(a[i]=='A')
		printf("sae");
		else if(a[i]=='(')
		{
			i++;int l=i;
			for(;;i++)
			{
				if(a[i]==')') break;
			}
			int r=i-1;cout<<a[l];
			for(int j=r;j>l;j--)
			{
				cout<<a[j]<<a[l];
			}
		}
	}
	return 0;

