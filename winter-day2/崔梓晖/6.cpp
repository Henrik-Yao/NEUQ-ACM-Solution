#include <bits/stdc++.h>
using namespace std;
int n,t=0;
int xian[1001],zhong[1001],ans[1001];
void deal(int l1,int r1,int l2,int r2)
{
	if(r1<l1)
	return;
	ans[++t]=xian[l2];
	int pos=-1;
	for(int i=l1;i<=r1;i++)
	{
		if(zhong[i]==xian[l2])
		pos=i;
	}
	deal(pos+1,r1,r2-(r1-pos-1),r2);
	deal(l1,pos-1,l2+1,l2+1+(pos-1-l1));
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>xian[i];
	}
	for(int i=0;i<n;i++)
	{
		cin>>zhong[i];
	}
	deal(0,n-1,0,n-1);
	for(int i=t;i>=1;i--)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

