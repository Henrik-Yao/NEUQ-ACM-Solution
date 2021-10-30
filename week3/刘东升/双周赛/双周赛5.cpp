#include<bits/stdc++.h> 
using namespace std;
const int M=200;
int a[M];
int main()
{
	int n,i;cin>>n;
	while(n--)
	{
		int m,n;
		cin>>m;
		for(i=0;i<m;i++)
		{
			cin>>a[i];
		}
		cin>>n;
		for(i=m;i<m+n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+m+n);//ÎÞÄÔsort 
		for(i=0;i<m+n;i++)
		{
			cout<<a[i];
			if(i!=m+n-1)
			{
				cout<<" ";
			}
		}
		if(n)
		{
			cout<<endl;
		}
	}
}
