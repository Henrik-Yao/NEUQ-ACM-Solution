#include<iostream>
using namespace std;
int n,a[1000000],l[1000000],r[1000000],bkt[100001],maxh=-9999;
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	l[0]=1;bkt[a[0]]=1;
	for (int i=1;i<n;i++)
	if (bkt[a[i]]==0)
	{
	l[i]=l[i-1]+1;
	bkt[a[i]]++;
	}
	else
	{
		l[i]=l[i-1];
	}
	for (int i=0;i<100001;i++)
	bkt[i]={0};
	r[n-1]=1;bkt[a[n-1]]=1;
	for (int i=n-2;i>=0;i--)
	if (bkt[a[i]]==0)
	{
	r[i]=r[i+1]+1;
	bkt[a[i]]++;
	}
	else
	{
		r[i]=r[i+1];
	}
	for (int i=0;i<n;i++)
	if (l[i]+r[i]>maxh)
	maxh=l[i]+r[i+1];
	cout<<maxh;
	return 0;
}