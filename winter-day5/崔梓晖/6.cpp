#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	while(cin>>n) 
	{
		int a[101],m,q[101];
		for(int i=1; i<=n; i++) 
		{
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		cin>>m;
		for(int i=1; i<=m; i++) 
		{
			cin>>q[i];
		}
		for(int i=1; i<=n-1; i++) 
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n]<<endl;
		for(int i=1; i<=m; i++) 
		{
			int l=1,r=n,pd=0;
			while(l<=r) 
			{
				int mid=(l+r)/2;
				if(q[i]==a[mid]&&i<m) 
				{
					cout<<mid<<" ";
					pd=1;
					break;
				}
				if(q[i]==a[mid]&&i==m) 
				{
					cout<<mid;
					pd=1;
					break;
				}
				if(q[i]>a[mid]) 
				{
					l=mid+1;
				}
				if(q[i]<a[mid]) 
				{
					r=mid-1;
				}
			}
			if(pd==0&&i<m) 
			{
				cout<<"0"<<" ";
			}
			if(pd==0&&i==m) 
			{
				cout<<"0";
			}
		}
	}
	return 0;
}
  
