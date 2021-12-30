#include <bits/stdc++.h>
using namespace std;
int n;
void print(int *a)
{
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void quicksort(int *a,int left,int right)
{
	if(left>=right)
	{
		return;
	}
	int l=left;
	int r=right;
	int key=a[left];
	while(l<r){
		while(l<r&&a[r]>key)
		{
			r--;
		}
		while(l<r&&a[l]<=key)
		{
			l++;
		}
		swap(a[r],a[l]);
	}
	swap(a[l],a[left]);
	print(a);
	quicksort(a,left,l-1);
	quicksort(a,l+1,right);
}
int main()
{
	cin>>n;
	int a[n]; 
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	return 0;
}
