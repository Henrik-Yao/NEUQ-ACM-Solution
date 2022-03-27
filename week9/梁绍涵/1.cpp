#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m,sum,a[10000],s[10000];
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];	
	}
	sort(a,a+n);
	int len;
	len=a[n-1]-a[0]+1;
	for(int i=0;i<n-1;i++)
	{
		s[i]=a[i+1]-a[i]-1;
	}
	sort(s,s+n-1,cmp);
	sum=len;
	for(int i=0;i<m-1;i++)
    {
    	sum=sum-s[i];
    }
    cout<<sum;
} 
