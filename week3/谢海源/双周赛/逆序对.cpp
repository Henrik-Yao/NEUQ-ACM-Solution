#include<bits/stdc++.h>
using namespace std;
#define ll long long
int a[1000005],b[1000005];
ll s=0;
void f(int l,int mid,int r)
{
	int i=l,j=mid+1,t=0;//指针
	while(i<=mid&&j<=r)
	{
		if(a[i]>a[j])//左边指的数大于右边时
		{
			b[t++]=a[j++];
			s=s+mid+1-i;//i指针及后的的数都能与j指的数构成逆序对，记录逆序对数量
		}
		else b[t++]=a[i++];
	}
	while(i<=mid)
	{
		b[t++]=a[i++];
	}
	while(j<=r)
	{
		b[t++]=a[j++];
	}
	for(int k=0;k<t;k++) a[l+k]=b[k];//将排序好的数复制回去
}
void fsort(int l,int r)//分左右排
{
	if(l<r)
	{
		int mid=(l+r)/2;
		fsort(l,mid);
		fsort(mid+1,r);
		f(l,mid,r);
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	fsort(0,n-1);
	cout<<s;
	return 0;	
}
