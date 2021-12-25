#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
    m--;
	int a[n],dis[n-1];
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n-1;i++) dis[i]=(a[i+1]-a[i])-1;
	int sum=(a[n-1]-a[0])+1;
	sort(dis,dis+(n-1));
	for(int i=0;i<m;i++) sum-=dis[(n-2)-i];
	cout<<sum;
	return 0;
} 
