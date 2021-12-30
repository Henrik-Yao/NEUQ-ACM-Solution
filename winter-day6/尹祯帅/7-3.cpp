#include<bits/stdc++.h>
using namespace std;
int sum[55];
int main()
{
	int n;
	int a;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a;
		sum[a]+=1;
	}
	for(int i=0;i<=50;i++)
	{
		if(sum[i]) cout<<i<<":"<<sum[i]<<'\n';
	}
	return 0;
} 
