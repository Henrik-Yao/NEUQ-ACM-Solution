#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,ans;
int a[2000005],b[2000005];
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i;i=b[i])
	{
		int tmp=0;
		int xx=0;
		for(int j=1;(j<=a[i]);j++)
		{
			if(tmp<i+j+a[i+j])
			{
				tmp=i+j+a[i+j];
				xx=i+j;
			}
		}
		b[i]=xx;ans++;
		if(tmp>=n)
		{
			ans++;
			break;
		}
	}
	cout<<ans;
	return 0;
}

