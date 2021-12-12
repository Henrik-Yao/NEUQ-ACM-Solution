#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int t;
int n;
struct tim
{
	int be,en;
}a[1005];
int f[1005];
bool cmp(tim x,tim y)
{
	return x.en<y.en;
}

int main()
{
	cin>>t;
	while(t--)
	{
		vector<int>b[25];
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i].be>>a[i].en;
		}
		sort(a+1,a+1+n,cmp);
		int now=0;
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(a[now].en<=a[i].be)
			{
				now=i;
				ans++;
			}
		}
		cout<<n-ans<<endl;
	}
	return 0;
}
