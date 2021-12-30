#include<bits/stdc++.h>
using namespace std;
int a[1005];
void max_heapify(int start,int end)
{
	int dad=start,son=2*start+1;
	while(son<=end)
	{
		if(son+1<=end&&a[son]<a[son+1])
		son++;
		if(a[son]<a[dad])
		return;
		else
		{
			swap(a[son],a[dad]);
			dad=son;
			son=dad*2+1;
		}
	}
}
void heap_sort(int n)
{
	for(int i=n/2-1;i>=0;i--)
	max_heapify(i,n-1);
	for(int i=0;i<n;i++)
	cout<<a[i]<<" ";
	cout<<endl;
	for(int i=n-1;i>0;i--)
	{
		swap(a[0],a[i]);
		max_heapify(0,i-1);
		for(int j=0;j<n;j++)
		cout<<a[j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	heap_sort(n);
}
