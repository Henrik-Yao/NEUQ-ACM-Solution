#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,T,ans=-111111110;
 	cin>>n>>T;
 	while(n--)
 	{
 		int v,t;
 		cin>>v>>t;
 		if(t>T)
 		ans=max(ans,v-t+T);
 		else
 		ans=max(ans,v);
	}
	cout<<ans;
}
