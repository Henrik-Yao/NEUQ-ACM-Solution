#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long t,c,i,j,m,a,b;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a>>b>>c;
		m=1;
		for(j=0;j<b;j++)
		{
			m*=a;
			m%=c;
		}
		cout<<m<<endl;
	}
	return 0;
}

