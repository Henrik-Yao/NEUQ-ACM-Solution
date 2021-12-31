#include<bits/stdc++.h>
using namespace std;
char temp[100],a[100];
int vis[100]={0};
void dfs(int from,int to)
{
	if(from>to)
	{
		cout<<temp<<endl;
		return ;
	}
	for(int i=0;i<=to;i++)
	{
		if(vis[i]==0)
		{
			temp[from]=a[i];
			vis[i]=1;
			dfs(from+1,to);
			vis[i]=0;
		}
	}
}
int main()
{
	cin>>a;
	sort(a,a+strlen(a)); 
	dfs(0,strlen(a)-1);
}
