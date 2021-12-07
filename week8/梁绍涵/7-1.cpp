#include<bits/stdc++.h>
using namespace std;
int t;
struct p
{
	int str,end;
}a[10000];
bool cmp(p x,p y)
{
	return x.end<y.end;
}
int main()
{
	cin>>t;
	while(t--)
	{
		int n,ans=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].str>>a[i].end; 
		}
		sort(a,a+n,cmp);
		int j=0;
		for(int i=1;i<n;i++)
		{
			if(a[i].str>=a[j].end)
			{
				j=i;
				ans++;
			}			
		}
		cout<<n-ans<<endl;
	}
}