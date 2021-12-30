#include <bits/stdc++.h>
using namespace std;
int a[101];
int main()
{
	int n,i,j,k,t,m,mid;
	while(cin>>n)
	{
		for(i=0;i<n;i++)	cin>>a[i];
		cin>>m;
		for(i=0;i<n;i++)
		{
			t=a[i];
			k=i;
			for(j=i+1;j<n;j++)
			if(t>a[j])
			{
				t=a[j];
				k=j;
			}
			a[k]=a[i];
			a[i]=t;
		}
		for(i=0;i<n;i++)	
		{
			cout<<a[i];
			if(i!=n-1)	cout<<' ';
		}
		cout<<endl;
		while(m--)
		{
			cin>>t;
			int left=0;
			int right=n-1;
			bool flag=0;
			while(left<=right)
			{
				mid=(left+right)/2;
				if(a[mid]==t)
				{
					flag=1;
					break;
				}
				else if(a[mid]<t)	left=mid+1;
				else if(a[mid]>t)	right=mid-1;	
			}
			if(flag)	cout<<mid+1;	
			else cout<<"0";
			if(m)	cout<<' ';
			else cout<<endl;
		}
	}
	return 0;
}
