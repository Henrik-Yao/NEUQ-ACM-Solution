#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[41]={0,0,1,2};
int main()
{
	for(int i=4;i<=40;i++)
	{
		a[i]=a[i-1]+a[i-2];
	}
	int k,x;
	cin>>k;
	while(k--)
	{
		scanf("%d",&x);
		printf("%d\n",a[x]);
	}
	return 0;
}
