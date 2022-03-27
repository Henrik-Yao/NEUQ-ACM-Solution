#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m,a[1000005],d[1000005],ans;
bool comp(int a,int b)
{
	return a>b;
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+n+1);
	ans=a[n]-a[1]+1;
	for(int i=1;i<n;i++)
	d[i]=a[i+1]-a[i]-1;
	sort(d+1,d+n,comp);
	for(int i=1;i<=m-1;i++)
	ans-=d[i];
	cout<<ans;
	return 0;
}

