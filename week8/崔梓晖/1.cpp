#include <bits/stdc++.h>
using namespace std;
struct ty
{
	int begin;
	int end;
}a[1001];
bool cmp(ty x,ty y)
{
	return x.end<y.end;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,minn=-1,ans=1;
		cin>>n;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].begin>>a[i].end;	
		}
		sort(a+1,a+n+1,cmp);
		minn=a[1].end;
		for(int i=2;i<=n;i++)
		{
			if(a[i].begin>=minn)
			{
				ans++;
				minn=a[i].end;
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}
