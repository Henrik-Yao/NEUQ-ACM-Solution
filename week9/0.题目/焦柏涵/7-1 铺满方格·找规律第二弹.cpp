#include <bits/stdc++.h>
using namespace std;
#define ll long long
int a[10001]={0,1,2,4},m=3;
int gupai(int i)
{
	if(i<=m) return a[i];
	a[i]=gupai(i-1)+gupai(i-2)+gupai(i-3);
	m=i;
	return a[i];
}
int main()
{
	int n;
	gupai(50);
	while(cin>>n)
	{
		cout<<gupai(n)<<endl;
	}
}
