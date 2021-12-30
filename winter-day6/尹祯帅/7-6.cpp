#include<bits/stdc++.h>
using namespace std;
long long a[10000],n;
void quicksort(int left,int right)
{
	if(left>=right) return ;
	int l=left,r=right;
	int key = a[left];
	while(l<r)
	{
		while(l<r&&a[r]>key) r--;
		while(l<r&&a[l]<=key) l++;
		swap(a[r],a[l]);
	}
	swap(a[l],a[left]);
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout<<'\n';
	quicksort(left,l-1);
	quicksort(l+1,right);
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	quicksort(0,n-1);
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout<<'\n';
	return 0;
} 
