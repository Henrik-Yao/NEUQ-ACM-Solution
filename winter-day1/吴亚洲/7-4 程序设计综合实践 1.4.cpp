#include<bits/stdc++.h>
#define ll long long
using namespace std;
int a[10000],b[10000],c[1000],n=1,k1=1,k2=1;
int main()
{
	int x;
	while(cin>>x)
	{
		a[n++]=x;
		if(x%2==0)
		c[k2++]=x;
		else b[k1++]=x;
	}
	n--;k1--;k2--;
	sort(a+1,a+n+1);
	sort(b+1,b+k1+1);
	sort(c+1,c+k2+1);
	for(int i=1;i<=n;i++)
	{
		if(i!=n)cout<<a[i]<<"->";
		else cout<<a[i];
	}
	cout<<endl;
	for(int i=1;i<=k1;i++)
	{
		if(i!=k1)cout<<b[i]<<"->";
		else cout<<b[i];
	}
	cout<<endl;
		for(int i=1;i<=k2;i++)
	{
		if(i!=k2)cout<<c[i]<<"->";
		else cout<<c[i];
	}
	cout<<endl;
	return 0;
}

