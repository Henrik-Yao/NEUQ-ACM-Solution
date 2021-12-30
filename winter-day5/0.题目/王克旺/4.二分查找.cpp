#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,x,count=0,a[1000];
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	cin>>x;
	int start=0,end=n-1;
	while(start<=end)
	{
		int mid=(start+end)/2;
		count++;
		if(a[mid]>x)
		{
			end=mid-1;
		}
		else if(a[mid]<x)
		{
			start=mid+1;
		}
		else if(a[mid]==x)
		{
			cout<<mid<<endl<<count<<endl;
			return 0;
		}
	}
	cout<<-1<<endl<<count<<endl;
	return 0;
}
