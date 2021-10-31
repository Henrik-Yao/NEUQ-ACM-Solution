#include <bits/stdc++.h>
using namespace std;
int t,m,n,a[100001];
int main()
{
	cin>>t;
	while(t--)
	{
        memset(a,0,sizeof(a));
		cin>>m;
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		}
		cin>>n;
		for(int i=m+1;i<=m+n;i++)
		{
			cin>>a[i];
		}
    sort(a+1,a+m+n+1);
	for(int i=1;i<=m+n-1;i++)
	cout<<a[i]<<" ";
    cout<<a[m+n];
    cout<<endl;
	}
	return 0;
}
