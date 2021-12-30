#include<bits/stdc++.h>
using namespace std;
long long a[10000],n;
void down(int pre,int size)
{
	int child = pre*2+1;
	while(child<size)
	{
		if(child+1<size&&a[child]<a[child+1]) child++;
		if(a[child]>a[pre]) 
		{
			swap(a[child],a[pre]);
			pre = child;
		}
		child= child*2+1;
	}
}
void init()
{
	for(int i=n/2-1;i>=0;i--)	down(i,n);
}
void heapsort()
{
	init();
	for(int i=0;i<n;i++) cout<<a[i]<<' ';
	cout<<'\n';
	for(int k=n-1;k>0;k--) 
	{
		
		swap(a[0],a[k]);
		down(0,k);
		for(int j=0;j<n;j++) cout<<a[j]<<' ';
		cout<<'\n';
	}
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)	cin>>a[i];
	heapsort();
	return 0;
} 
