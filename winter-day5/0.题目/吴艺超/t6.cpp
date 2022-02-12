#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[105];
int query(int l,int r,int x)
{
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]>=x)r=mid;else l=mid+1;
	}
	return (a[l]==x)?l:0;
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+n+1);
		cin>>q;
		for(int i=1;i<=n-1;i++)
			cout<<a[i]<<" ";
		cout<<a[n]<<endl;
		for(int i=1;i<=q;i++)
		{
			int x;
			cin>>x;
			cout<<query(1,n,x);	
			if(i!=q)cout<<" ";
		}
		cout<<endl;
	}
} 
