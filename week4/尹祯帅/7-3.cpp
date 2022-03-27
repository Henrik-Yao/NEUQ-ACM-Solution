#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=10000001;
bool ss[maxn];
int sum[maxn];
int main()
{
	cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!ss[i]) sum[++sum[0]]=i;
		for(int j=1;j<=sum[0]&&i*sum[j]<=n;j++)
		{
			ss[i*sum[j]]=1;
			if(i%sum[j]==0) break;
		}
	}
	cout<<sum[0];
	return 0;
 } 

