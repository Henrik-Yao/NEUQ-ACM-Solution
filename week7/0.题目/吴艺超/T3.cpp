#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
} 
string a,b;
bool c[10000000];
int main()
{
	while(getline(cin,a)&&getline(cin,b))
	{
		memset(c,0,sizeof(c));
		int len1=a.length();
		int len2=b.length();
		for(int i=0;i<len2;i++)
		{
			int x=b[i];
			c[x]=1;
		}
		for(int i=0;i<len1;i++)
		{
			int x=a[i];
			if(c[x]==0)printf("%c",a[i]);
		}
		printf("\n");
	}
	return 0;
}
