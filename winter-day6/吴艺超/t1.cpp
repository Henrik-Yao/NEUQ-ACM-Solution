#include<bits/stdc++.h>
#pragma GCC optimize(1)
using namespace std;
int n,a[105];
int main()
{
	while(cin>>n)
	{
	for(int i=1;i<=n;i++)
	cin>>a[i];
	if(n==1)
	{
		cout<<a[1]<<endl;
		continue;
	}
	int i,j;
	for( i=2;i<=n;i++)
	{
		if(a[i]<a[i-1]){
			a[0]=a[i];
		for( j=i-1;a[0]<a[j];j--){
			a[j+1]=a[j];
		}
		a[j+1]=a[0];
		}
		for(int q=1;q<=n-1;q++)
		cout<<a[q]<<" ";
		cout<<a[n]<<endl;
	}
	}
	return 0;
}
