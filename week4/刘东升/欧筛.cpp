#include<bits/stdc++.h>
using namespace std;
const int M=10000001;
int vis[M],pri[M/2];
int main()
{
	int n,ans=0;cin>>n;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			pri[++ans]=i;//记录素数 
		}
		for(int j=1;j<=ans;j++)//筛质因数 
		{
			if(i*pri[j]>n) break;
			vis[i*pri[j]]=1;
			if(i%pri[j]==0) break;
		}
	}
	cout<<ans;
} 
