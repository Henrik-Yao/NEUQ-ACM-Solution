#include<bits/stdc++.h>
#define int long long
using namespace std;
int a,b,p,ans=1;
int qm(int x,int y,int z)
{
	int ans=1;
	x=x%z;
	if(y==0)
	{
		ans=1%z;
	}
	while(y>0)
	{
		if(y%2==1)
			ans=(ans*x)%z;
		y=y/2;
		x=(x*x)%z;
	}
	return ans;
}
signed main()
{
	int t;
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>a>>b>>p;
		if(t==i)
		cout<<qm(a,b,p);
		else
		cout<<qm(a,b,p)<<endl; 
	}

}	
