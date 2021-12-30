#include<bits/stdc++.h>
using namespace std;
int n,x,sum=0;
int a[2000];
int binarysearch()
{
	int left=0;
	int right=n-1;
	while(left<=right)
	{
		sum++;
		int middle=(left+right)/2;
		if(a[middle]==x) return middle;	
		if(a[middle]<x)
		{
			left=middle+1;	
		}
		else
		right=middle-1;		
	}
	return -1;
}
int main()
{ 
	int ans;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}	
	cin>>x;
	ans=binarysearch();
	cout<<ans<<endl<<sum; 
} 
