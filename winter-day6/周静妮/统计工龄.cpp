#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,i,j,k,t=0;
	int a[51]={0};
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>k;
		a[k]++;
		t=max(k,t);
	}
	for(i=0;i<=t;i++)
		if(a[i]) cout<<i<<":"<<a[i]<<endl;
	return 0;
}
