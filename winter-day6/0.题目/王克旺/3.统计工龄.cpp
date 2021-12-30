#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100000],b[51]={0};
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	sort(a,a+n);
	for(int i=0;i<n;i)
	{
		cout<<a[i]<<":"<<b[a[i]]<<endl;
		i=i+b[a[i]];
	}
	return 0;
}
