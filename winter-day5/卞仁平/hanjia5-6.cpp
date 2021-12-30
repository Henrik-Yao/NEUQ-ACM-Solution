#include<bits/stdc++.h>
using namespace std;
int x;
int find(int a[],int q,int n)
{
	n--;
	while(n>=q)
	{
		int mid=(n+q)/2;
		if(a[mid]<x) q = mid+1;
		else if(a[mid]>x) n=mid-1;
		else return mid;
	}
	return -1;
}
int main()
{
	int n;
	while(cin>>n)
	{
		int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++) 
	{
		cout<<a[i];
		if(i!=n-1) cout<<' ';
	}
	cout<<'\n';
	int m;
	cin>>m;
	while(m--)
	{
		cin>>x;
	cout<<find(a,0,n)+1;
	if(m!=0) cout<<' ';
	 } 
        cout<<endl;
	}
	
	return 0;
} 
