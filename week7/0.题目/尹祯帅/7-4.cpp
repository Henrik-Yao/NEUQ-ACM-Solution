#include<bits/stdc++.h>
using namespace std;
void dp(int a[],int l[],int n)
{
	for(int i=0;i<n;i++)
	for(int j=0;j<i;j++)
	if(a[j]<a[i]&&l[j]>=l[i]) l[i]=l[j]+1;
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  	int n,maxn=0;
  	cin>>n;
  	int a[n],l[n];
	  memset(l,0,sizeof(l));
  	for(int i=0;i<n;i++) cin>>a[i],l[i]++;
  	dp(a,l,n);
  	for(int i=0;i<n;i++) maxn=max(maxn,l[i]);
  	cout<<maxn<<'\n';
    if(t) cout<<'\n';
  }
  return 0;
}

