#include <bits/stdc++.h>
using namespace std;

long long a[100010];
void qsort(int lef,int rig)
{
	long long x=a[lef];
	int i=lef, j=rig;
	
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i], a[j]);
			i++;
			j--;
		}
	}
	if(i<rig)
		qsort(i, rig);
	if(j>lef)
		qsort(lef, j);
}
int main(void)
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>a[i];
	qsort(0, n-1);
	for(int i=0; i<n; i++)
		cout<<a[i]<<' ';
	
	return 0;
}