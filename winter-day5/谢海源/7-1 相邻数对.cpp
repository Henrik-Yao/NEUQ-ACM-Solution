#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4;
const int INF = 1e6;
int a[maxn];
bool v[maxn][maxn]={};
int main()
{
	int n,sum=0;
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i==j||v[a[i]][a[j]])continue;
			if(a[i]-a[j]==1)
			{
				sum++;
				v[a[i]][a[j]]=1;//标记已出现的数对
			}
		}
	}
	cout<<sum;
	return 0;
}