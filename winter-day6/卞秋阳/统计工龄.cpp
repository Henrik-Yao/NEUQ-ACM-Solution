#include<bits/stdc++.h>
using namespace std;
int x;
int n;
const int maxn = 1e5+5;
int a[maxn]={};
int main()
{
	cin>>n;
	for (int i=0;i<n;i++)
	{
		cin>>x; 
		a[x]++;
	}
	for (int i=0; i<maxn;i++)
	{
		if(a[i]) printf("%d:%d\n",i,a[i]);
	}
	return 0;
} 
