#include <bits/stdc++.h>
using namespace std;
int zlt(int m)
{
	if(m==1) return 0;
	if(m==2) return 1;
	if(m==3) return 2;
	return zlt(m-1)+zlt(m-2);
}
int main()
{
	int n,m;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		cout<<zlt(m)<<endl;
	}
	return 0;
}
