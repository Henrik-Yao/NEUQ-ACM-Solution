#include<bits/stdc++.h>
using namespace std;
int sum=0;
int x;
int find(int a[],int q,int n)
{
	n--;
	while(n>=q)
	{
		sum++;
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
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>x;
	cout<<find(a,0,n)<<endl;
	cout<<sum;
	return 0;
} 
