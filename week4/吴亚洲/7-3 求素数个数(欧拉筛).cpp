#include<bits/stdc++.h>
using namespace std;
bool judge[10000005];
int a[10000005];
int main()
{
	memset(judge,false,sizeof(judge));
	int n,cnt=0;
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!judge[i])
		a[++cnt]=i;
		for(int j=1;j<=cnt&&i*a[j]<=n;j++)
		{
			judge[i*a[j]]=true;
			if(i%a[j]==0)
			break;
		}
	}
	cout<<cnt;
}
