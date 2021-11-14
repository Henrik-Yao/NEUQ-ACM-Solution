#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m,n,i,j;
	long long a[41];
	a[1]=0;
	a[2]=1;
	a[3]=2;
	for(i=4;i<=40;i++)
		a[i]=a[i-1]+a[i-2];
	cin>>n;
	while(n--)
	{
		cin>>m;
		cout<<a[m]<<endl;
	}
	return 0;
}
