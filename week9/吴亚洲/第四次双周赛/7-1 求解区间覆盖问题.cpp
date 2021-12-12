#include<bits/stdc++.h>
using namespace std;
#define M 100000
int len[M],p[M];
bool cam(int x,int y)
{
	return x>y;
}
int main()
{
	int ans,n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>p[i];
	sort(p,p+n);
	ans=p[n-1]-p[0]+1;
	for(int i=1;i<n;i++)
	len[i]=p[i]-p[i-1]-1;
	sort(len+1,len+n,cam);
	for(int i=1;i<=m-1;i++)
	ans-=len[i];
	cout<<ans;
} 
