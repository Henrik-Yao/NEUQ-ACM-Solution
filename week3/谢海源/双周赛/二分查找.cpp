#include<bits/stdc++.h>
using namespace std;
int a[1000001];
int x;
int cha(int a[],int l,int r)
{
	int t=0;
	if(l==r) return l;
	int mid=(l+r)/2;
	if(a[mid]>=x)
	{
		t=cha(a,l,mid);
	}
	else
	{
		t=cha(a,mid+1,r);
	}
	return t;
}
int main()
{
	int n;
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int t=cha(a,1,n);
	if(a[t]>=x) cout<<t<<endl;
	else cout<<n+1<<endl;
	return 0;	
}
