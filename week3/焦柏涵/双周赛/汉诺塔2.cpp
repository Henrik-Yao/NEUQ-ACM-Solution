#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	double m[70],l[70];
	//memset(l,1000000,sizeof(l));
	//还是不知道这个对不对，一会儿再试试 
	m[1]=l[1]=1;
	for(int i=2;i<=64;i++)
	{
		m[i]=2*m[i-1]+1;
		l[i]=1000000;
	}
	for(int i=2;i<=64;i++) 
	{
		for(int j=1;j<i;j++)
		{
			l[i]=min(l[i],m[i-j]+2*l[j]);
		}
	}
	while(cin>>n) cout<<l[n]<<endl;
	return 0;
}
