#include<bits/stdc++.h>
using namespace std;
int n,t;
int ans=-1e7;
int main()
{
	cin>>n>>t;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		if(b>t)
		{
			if(a-(b-t)>=ans)ans=a-(b-t);
		}
		else if(b<=t)
		{
			if(a>=ans)ans=a;
		}
	}
	cout<<ans;
	return 0;
}
