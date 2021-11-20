#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char t[1000005],p[1000005];
int nex[1000005];
int f[1000005];
int ans=0;
void start_next(char a[])
{
	nex[0]=0;
	int len=strlen(a);
	for(int i=1,j=0;i<len;i++)
	{
		while(j>0&&a[i]!=a[j])j=nex[j-1];
		if(a[i]==a[j])j++;
		nex[i]=j;
	}
}
void start_f(char a[],char b[])
{
	int len=strlen(b);
	for(int i=0,j=0;i<len;i++)
	{
		while(j>0&&b[i]!=a[j])j=nex[j-1];
		if(b[i]==a[j])j++;
		if(j==strlen(a))ans++;
	}
}
int main()
{
	cin>>t>>p;
	start_next(p);
	start_f(p,t);
	cout<<ans;
	return 0;
}
