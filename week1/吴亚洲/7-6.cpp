#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,T,kl,max=-0x7ffffff;
	cin>>n>>T;
	int v[100001],t[100001];
	for(int i=1;i<=n;i++)
	{
		cin>>v[i]>>t[i];
		if(t[i]<=T)
		kl=v[i];
		else
		kl=v[i]-(t[i]-T);
		if(kl>max)
		max=kl;
	}
	cout<<max;
	return 0;
}
