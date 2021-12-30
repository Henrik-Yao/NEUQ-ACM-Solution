#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200];
int binary(int x)
{
	int left=1,right=n;
	while(left<=right)
	{
		int mid=(left+right)/2;
		if(a[mid]==x) return mid;
		if(a[mid]<x) left=mid+1;
		else right=mid-1;
	}
	return 0;
}
int main()
{
	while(cin>>n)
	{
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		cin>>m;
		for(int i=0;i<m-1;i++){
			int num;
			cin>>num;
			cout<<binary(num)<<" ";
		}
		int num;
		cin>>num;
		cout<<binary(num);
		cout<<endl;
	}

	
}
