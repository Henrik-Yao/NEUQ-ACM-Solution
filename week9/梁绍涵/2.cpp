#include<bits/stdc++.h>
#define int long long
using namespace std;
int s(int k)
{
	if(k==1) return 1;
	if(k==2) return 2;
	if(k==3) return 4;
	if(k==4) return s(k-1)+s(k-2)+s(k-3);
}
signed main()
{
	int n,a[51];
	a[1]=1;
	a[2]=2;
	a[3]=4;
	for(int i=4;i<=50;i++)
	{
		a[i]=a[i-1]+a[i-2]+a[i-3];
	}
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}
}

