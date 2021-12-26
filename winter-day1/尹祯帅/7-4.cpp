#include <bits/stdc++.h>
using namespace std;
map<int ,long long > a,b,c;
int main()
{
	int n=0;
	while(scanf("%lld",&a[n])!=EOF) n++;
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	{
		if(a[i]>a[j]) swap(a[i],a[j]);
	}
	int q=0,w=0;
	for(int i=0;i<n;i++)
	{
		cout<<a[i];
		if(i!=n-1) cout<<"->";
		if(a[i]%2==0)
		{
			b[q]=a[i];
			q++;
		}
		else
		{
			c[w]=a[i];
			w++;
		}
	}
	cout<<'\n';
	for(int i=0;i<w;i++) 
	{
		cout<<c[i];
		if(i!=w-1) cout<<"->";
	 } cout<<'\n';
	 for(int i=0;i<q;i++) 
	{
		cout<<b[i];
		if(i!=q-1) cout<<"->";
	 } ;
	return 0;
}
