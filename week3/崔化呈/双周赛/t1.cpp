#include<bits/stdc++.h>
using namespace std;
const int minn=-1234556666;
int n,arr[201000];
int max(int a,int b)
{
	return a>b?a:b;
}
int fen(int l,int r)
{
	if(l==r)
	{
		return arr[l];
	}
	else{}
	int mid=(l+r)>>1;
	int sum=0,re1=minn,re2=minn;
	for(int i=mid;i>=l;i--)
	{
		sum+=arr[i];
		re1=max(sum,re1);
	}
	sum=0;
	for(int i=mid+1;i<=r;i++)
	{
		sum+=arr[i];
		re2=max(re2,sum);
	}
	return max(max(fen(l,mid),fen(mid+1,r)),re1+re2);
	
}
int main()
{
    int flag=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&arr[i]);
        if(arr[i]>=0){flag=1;}
	}
    if(flag){cout<<fen(1,n)<<endl;}
    else{cout<<0<<endl;}
	
	return 0;
}
