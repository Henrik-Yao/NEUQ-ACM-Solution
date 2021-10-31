#include<bits/stdc++.h>
using namespace std;
int n,x,wei;
int a[1001000];

int erfen(int l,int r,int g)
{
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(g>a[mid])
		{
			l=mid+1;
		}
		else
		{
			r=mid-1;
		}
	}
	return l;
}
int main()
{
	cin>>n>>x;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	wei=erfen(1,n,x);
	cout<<wei<<endl;
	return 0;
}
