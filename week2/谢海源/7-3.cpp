#include<bits/stdc++.h>
using namespace std;
void fhb(int a[],int l,int r,int mid)//合并数组
{
	int t[r-l+1];//寄存数组
	for(int k=l;k<=r;k++) t[k-l]=a[k];
	
	int i=l,j=mid+1;
	
	for(int k=l;k<=r;k++)//从l到r插入数组a中
	{
		if(i>mid)//左半部分已存完
		{
			a[k]=t[j-l];
			j++;
		}
		else if(j>r)//右半部分已存完
		{
			a[k]=t[i-l];
			i++;
		}
		else if(t[i-l]>t[j-l])
		{
			a[k]=t[j-l];
			j++;
		}
		else if(t[i-l]<=t[j-l])
		{
			a[k]=t[i-l];
			i++;
		}
	}
}
void fpx(int a[],int l,int r)//排序
{
	if(l>=r) return;
	
	int mid=(l+r)/2;
	
	fpx(a,l,mid);
	fpx(a,mid+1,r);//对左右进行排序
	fhb(a,l,r,mid);//再进行合并
}
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];//输入
	}
	fpx(a,0,n-1);//排序
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";//输出
	}
    return 0;
}