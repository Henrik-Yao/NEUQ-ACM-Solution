#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long a,b,c,d=1;
		cin>>a>>b>>c;
		while(b>0)
		{
			if(b%2==1)
			{
				d=d*a%c;
			}
			b=b/2;
			a=a*a%c;
		}
		cout<<d<<endl;
	}
	return 0;
}
