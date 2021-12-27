#include<bits/stdc++.h>
using namespace std;
#define lowbit(x) ((x)&(-x))
const int M=1e6+5;
long long c[M];
int n,q;
long long sum(int x)
{
	long long ans=0;
	for(;x>0;ans+=c[x],x-=lowbit(x));
	return ans;
}
void update(int x,int t)
{
	for(;x<=n;c[x]+=t,x+=lowbit(x));
}
int main()
{
	int a[M];
	cin>>n>>q;
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		update(i,a[i]);
	}
	while(q--)
	{
		int m,l,r;
		cin>>m>>l>>r;
		if(m==2)
		cout<<sum(r)-sum(l-1)<<endl;
		else
		update(l,r);
	}
}
