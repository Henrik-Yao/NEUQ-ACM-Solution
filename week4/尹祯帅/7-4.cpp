#include <bits/stdc++.h>
using namespace std;
int main()
{
	long long  n,a,b,c;
	long long s;
	cin>>n;
	while(n--)
	{
		cin>>a>>b>>c;
		a=a%c;
		s=1;
		while(b!=1)
		{
			if(b%2==1)
			{
				s=s*a;
				s=s%c;
			}
				a=a*a;
				a=a%c;
				b=b/2;
		}
        s=s*a;
        s=s%c;
		cout<<s<<'\n';
	}
	return 0;
}
