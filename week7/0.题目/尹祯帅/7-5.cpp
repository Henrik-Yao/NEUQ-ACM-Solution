#include<bits/stdc++.h>
using namespace std;
int dp(int w[],int v[],int n,int c)
{
	int sum[n+1][c+1];
	memset(sum,0,sizeof(sum));
	for(int i=1;i<=n;i++)
	for(int j=1;j<=c;j++)
	if(j<w[i]) sum[i][j]=sum[i-1][j];
	else sum[i][j]=max(sum[i-1][j],sum[i-1][j-w[i]]+v[i]);
	return sum[n][c];
}
int main()
{
    int n,c;
  while(scanf("%d",&n)!=EOF)
  {
  cin>>c;
  int w[n],v[n];
  for(int i=1;i<=n;i++) cin>>w[i];
  for(int i=1;i<=n;i++) cin>>v[i];
  cout<<dp(w,v,n,c)<<'\n';
  }
  return 0;
}

