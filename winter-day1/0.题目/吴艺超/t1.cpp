#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1000005],n,q;
int lowbit(int x)
{
	return x&-x;
}
void add(int x,int y)
{
	while(x<=n)
	a[x]+=y,x+=lowbit(x);
}
int query(int x)
{
	int ans=0;
	while(x!=0)
	ans+=a[x],x-=lowbit(x);
	return ans;
}
signed main()
{
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		add(i,x);
	}
	while(q--)
	{
		int x,y,z;
		cin>>x>>y>>z;
		if(x==1)
		add(y,z);
		else cout<<query(z)-query(y-1)<<endl;
	}
	return 0;
}
