#include <iostream>
using namespace std;
int main()
{
	int n,m,i,j,c,d;
	j=0;
	cin>>n>>m;
	int a[n];
	string b[n];
	for(i=0;i<n;i++)
		cin>>a[i]>>b[i];
	for(i=0;i<m;i++)
	{
		cin>>c>>d;
		if(a[j]==c) j-=d;
		else j+=d;
		if(j<0) j+=n;
		if(j>=n) j-=n;
	}
	cout<<b[j];
	return 0;
}
