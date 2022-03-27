#include<bits/stdc++.h>
using namespace std;
map<string,int> qs;
int n,ans;
int a[100];
void dfs(int x,int num,string q,int tot)
{
	if(num>n)
	{
		if(tot>1)
		ans++;
		return;
	}
	if(a[num]>=x)
	{
		int ch1=a[num]+100;
		char ch=ch1;
		string qq=q;
		q=q+ch;
		if(qs[q]==0)
		{
			qs[q]=1;
			dfs(a[num],num+1,q,tot+1);
			q=qq;
		}
		q=qq;
	}
	dfs(x,num+1,q,tot);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	dfs(-200,1,"",0);
	cout<<ans;
}
