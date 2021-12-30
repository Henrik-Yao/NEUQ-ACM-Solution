#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int a[maxn]={};
int main()
{
	int n;
	cin >> n;
	int x;
	for (int i = 0; i < n; i++)
	{
		scanf("%d",&x);
		a[x]++;
	}
	for (int i = 0; i < maxn; i++)
	{
		if(a[i]) printf("%d:%d\n",i,a[i]);
	}
	return 0;
}