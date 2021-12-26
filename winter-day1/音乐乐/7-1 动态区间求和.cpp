#include<bits/stdc++.h>
using namespace std;
long long c[1000010];
int lowbit(int x)
{
	return x&(-x);
}
void update(int j,int n,int x)
{
	for(int i=j;i<=n;i+=lowbit(i))
	{
		c[i]+=x;
	}
}
long long getsum(int add)
{
	long long ans=0;
	for(int i=add;i;i-=lowbit(i))
	{
		ans+=c[i];
	}
	return ans;
}
int main()
{
	int n,q,i;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		int a;
		scanf("%d",&a);
		update(i,n,a);
	}
	while(q--)
	{
		int op;
		cin>>op;
		if(op==1)
		{
			int j,x;
			cin>>j>>x;
			update(j,n,x);
		}
		if(op==2)
		{
			int l,r;
			cin>>l>>r;
			long long sum;
			sum=getsum(r)-getsum(l-1);
			//cout<<"L"<<getsum(l-1)<<endl;
			//cout<<"R"<<getsum(r)<<endl;
			cout<<sum<<endl;	
		}
	}
	return 0;
}
