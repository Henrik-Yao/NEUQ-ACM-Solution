#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
	int n,m,x;
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<n;i++)
		cout<<a[i]<<" ";
		cout<<a[n]<<endl;
		cin>>m;
		while(m--)
		{
			cin>>x;
			int l=1,r=n,cnt=0;
			bool judge=0;
			int ans[105];
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid]>x)
				r=mid-1;
				else if(a[mid]<x)
				l=mid+1;
				else
				{
					judge=1;
					if(m)
					cout<<mid<<" ";
					else
					cout<<mid;
					break;
				}
			}
			if(!judge)
			{
				if(m)
				cout<<0<<" ";
				else
				cout<<0;
			}
		}
		cout<<endl;
	}
}
