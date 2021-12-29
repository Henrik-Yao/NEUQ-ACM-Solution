#include<bits/stdc++.h>
using namespace std;
int n,q;
int a[1005];
void query(int l,int r,int x)
{
	int flag=0;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(a[mid]<=x)l=mid;else r=mid-1;
		flag++;
	}
	if(a[l]==x)
	{
		cout<<l<<endl<<flag;
	}
	else cout<<"-1"<<endl<<flag;
}
int main()
{
	cin>>n;	
	for(int i=0;i<n;i++)
		cin>>a[i];
	cin>>q;
	query(0,n-1,q);
} 
