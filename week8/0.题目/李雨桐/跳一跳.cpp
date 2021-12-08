#include<bits/stdc++.h>
using namespace std;

int a[1000005];
int sear(int n, int m);
int bian(int n,int m);

int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i];
	int k=0,res=1;
	while(k+a[k] < n-1)
	{
        int p=a[k];
		int m = sear(k,a[k]+k);
		k = bian(m,p+k);
		res ++;
	}
	cout<<res<<endl;
	return 0;
}

int sear(int n, int m)
{
	int ans = n+1;
	for(int i=n; i<=m;i++)
	{
		if(a[n]<a[i])
        {
			a[n]=a[i];
			ans=i;
		}
	}
	return ans;
}
int bian(int n,int m)
{
	int ans=n;
	for(int i=ans;i<=m;i++)
    {
		if(a[n] < a[i]+i-n)
			n=i;
	}
	return n;
}
