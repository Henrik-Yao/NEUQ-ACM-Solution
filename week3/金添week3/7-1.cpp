#include <bits/stdc++.h>
using namespace std;
int a[10000000];
int max(int a,int b)
{
	if(a>=b)
	return a;
	else
	return b;
}
int maxstringsum(int left,int right)
{
	if(left>=right)
	{
		if(a[left]<0)
		return 0;
		else
		return a[left];
	}	
	int mid=(right+left)/2;
	int leftsum=maxstringsum(left,mid);
	int rightsum=maxstringsum(mid+1,right);
	int sidemax=max(leftsum,rightsum);
	int sum=0,leftmax=a[mid],rightmax=a[mid+1];
	for(int i=mid;i>=left;i--)
	{
		sum=sum+a[i];
		leftmax=max(sum,leftmax);
		
	}
	sum=0;
	for(int i=mid+1;i<=right;i++)
	{
		sum=sum+a[i];
		rightmax=max(sum,rightmax);
		
	}
	int midsum=rightmax+leftmax;
	int finalmax=max(midsum,sidemax);
	return finalmax;
    
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	cout<<maxstringsum(1,n)<<endl;
	return 0;
 } 
