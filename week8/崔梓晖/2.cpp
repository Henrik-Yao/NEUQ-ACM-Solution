#include <bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
    int n,pos,next,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	pos=1;
	next=1+a[1];
	for(int i=2;i<=n;i++)
	{
		if(i>pos)
		{
			pos=next;
			ans++;
		}
		next=max(next,a[i]+i);
	}
	cout<<ans;
	return 0;
}
