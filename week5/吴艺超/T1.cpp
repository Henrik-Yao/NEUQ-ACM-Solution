#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(ch>'9' || ch<'0')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar(); 
	}
	return x*f;
}
struct ax{
	int fu=-1;
	int mu=-1;
	char x;
}a[100005];
int n,k,flag;
bool vis[100005];
void find(int x,int tot)
{
	if(vis[x])
	{
		flag=1;
		return;
	}
	vis[x]=1;
	if(tot==5)return;
	if(a[x].fu!=-1)
		find(a[x].fu,tot+1);
	if(a[x].mu!=-1)
		find(a[x].mu,tot+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int z;
		cin>>z;
		cin>>a[z].x>>a[z].fu>>a[z].mu;
//		if(a[z].fu!=-1)
		a[a[z].fu].x='M';
//		if(a[z].mu!=-1)
		a[a[z].mu].x='F';
	}
	cin>>k;
	while(k--)
	{
		int a1,b1;
		cin>>a1>>b1;
		if(a[a1].x == a[b1].x)
		{
			cout<<"Never Mind"<<endl;
			continue;
		}
		memset(vis,0,sizeof(vis));
		flag=0;
		find(a1,1);find(b1,1);
		if(flag==0)cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
