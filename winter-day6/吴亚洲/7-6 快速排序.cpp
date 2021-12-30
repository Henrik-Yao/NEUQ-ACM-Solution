#include<bits/stdc++.h>
using namespace std;
int n;
void quick_sort(int a[],int l,int r)
{
	if(l>=r)
	return ;
	int base=a[l];
	int i=l,j=r;
	while(i<j)
	{
		while(a[j]>base&&j>i)
		j--;
		while(a[i]<=base&&i<j)
		i++;
		if(i<j)
		{
			swap(a[i],a[j]);
		}
	}
	swap(a[l],a[i]);
	for(int k=0;k<n;k++)
	cout<<a[k]<<" ";
	cout<<endl;
	quick_sort(a,l,i-1);
	quick_sort(a,j+1,r);
}
int main()
{
	cin>>n;
	int a[10005];
	for(int i=0;i<n;i++)
	cin>>a[i];
	quick_sort(a,0,n-1);
	for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
}
