#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,m,a[100000],x,y,z=1;
	string b[100000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	for(int i=0;i<m;i++)
	{
		cin>>x>>y;
		if((a[z]==0&&x==0)||(a[z]==1&&x==1)) z=z-y;
		else if((a[z]==1&&x==0)||(a[z]==0&&x==1)) z=z+y;
		while(z<=0)
		{
			z=z+n;
		}
		while(z>n)
		{
			z-=n;
		}
	}
	cout<<b[z];
}
