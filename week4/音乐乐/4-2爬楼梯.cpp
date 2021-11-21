#include<iostream> 
using namespace std;
int f[41];

int main()
{
	f[1]=0;
	f[2]=1;
	f[3]=2;
	int i,n;
	for(i=4;i<=41;i++)
	{
		f[i]=f[i-1]+f[i-2];
	}
	cin>>n;
	while(n--)
	{
		int m;
		cin>>m;
		cout<<f[m]<<endl;
	}
	return 0;
}


