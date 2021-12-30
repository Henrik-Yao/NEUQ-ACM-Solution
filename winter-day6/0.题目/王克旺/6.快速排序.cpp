#include<bits/stdc++.h>
using namespace std;
int n,a[1000];
void quicksort(int a[1000],int low,int high)
{ 
	int l=low,h=high;
	if(low>=high)
	{
		return;
	}
	int temp=a[low];
	while(low<high)
	{
		while(low<high&&a[high]>temp)
		{
			high--;
		}
		while(low<high&&a[low]<=temp)
		{
			low++;
		}
		swap(a[low],a[high]);
	}	
	swap(a[low],a[l]);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	quicksort(a,l,low-1);
	quicksort(a,low+1,h);		
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}
	cout<<endl;
	return 0;
}
