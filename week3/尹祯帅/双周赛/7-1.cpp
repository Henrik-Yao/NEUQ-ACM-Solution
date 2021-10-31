#include<bits/stdc++.h>
using namespace std;
int max3(int a,int b,int c)
{
	int max=a;
	if(max<b) max=b;
	if(max<c) max=c;
	return max;
}
int sequence (int a[],int left,int right)
{
	if(left==right) return a[left];
	else
	{
		int middle =(left+right)/2;
		int leftmax=sequence(a,left,middle);
		int rightmax=sequence(a,middle+1,right);
		int temp=0,border,leftborder=0,rightborder=0;
		for(int i=middle;i>=left;i--)
		{
			temp+=a[i];
			if(temp>leftborder) leftborder=temp;
		}
		temp=0;
		for(int i=middle+1;i<=right;i++)
		{
			temp+=a[i];
			if(temp>rightborder) rightborder=temp;
		}
		border=leftborder+rightborder;
		return max3(leftmax,rightmax,border);
	}
}
int main()
{
	int n,a[10000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cout<<sequence(a,0,n-1)<<'\n';
	
	return 0;
}
