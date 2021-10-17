#include <bits/stdc++.h>
using namespace std;
int a[10000];
int ans(int v,int t,int T)
{
	if(t<=T)
	return v;
	else 
	return v-(t-T);
}
int main()
{
	int n,T,v,t;
	cin>>n>>T;
	for(int i=0;i<n;i++)
	{
		cin>>v>>t;
		a[i]=ans(v,t,T);
	}
	sort(a,a+n,greater<int>());
	cout<<a[0];
	return 0;
} s
