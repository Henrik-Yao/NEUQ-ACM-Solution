#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,cnt=0;
	int a[1000];
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	for(int j=i+1;j<=n;j++)
	if(abs(a[i]-a[j])==1)
	cnt++;
	cout<<cnt;
}
