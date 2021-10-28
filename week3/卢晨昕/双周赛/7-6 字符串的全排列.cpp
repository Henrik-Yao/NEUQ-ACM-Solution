#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
char a[10];
char b[10];
bool u[10];
int len;
bool cmp(char a,char b)
{
	return a<b;
}
void dfs(int now)
{
	if(now==strlen(a))
	{
		for(int i=0;i<now;i++)cout<<b[i];
		cout<<endl;
		return;
	}
	for(int i=0;i<strlen(a);i++)
	{
		if(u[i]!=1)
		{
			u[i]=1;
			b[now]=a[i];
			dfs(now+1);
			u[i]=0;
		}
	}
}
int main()
{
	cin>>a;
	sort(a,a+strlen(a),cmp);
	dfs(0);
	return 0;
}
