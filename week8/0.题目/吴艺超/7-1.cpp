#include<bits/stdc++.h>
#define ll long long
using namespace std;
int t;
int n;
struct ax{
	int x;
	int y;
}a[1000000];
bool comp(ax a,ax b)
{
	return a.y<b.y;
}
int main(){
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].x>>a[i].y;
		}
		sort(a+1,a+n+1,comp);
		int j=1;int ans=1;
		for(int i=2;i<=n;i++)
		{
			if(a[i].x>=a[j].y)
			{
				ans++;
				j=i;
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}

