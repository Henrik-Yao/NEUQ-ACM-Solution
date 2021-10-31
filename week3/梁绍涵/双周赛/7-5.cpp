#include<bits/stdc++.h>
using namespace std;
int a[10001],ans=0;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int m;
		cin>>m;
		for(int i=n+1;i<=n+m;i++)
		{
			cin>>a[i];
		}
		sort(a+1,a+1+m+n);
		cout<<a[1];
		for(int i=2;i<=m+n;i++)
		{
			cout<<" "<<a[i];
		}
		cout<<endl;
	}
}¡¢ 
