#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a,b,c,t,rol;
    cin>>t;
	for(int i=1;i<=t;i++)
	{
        rol=1;
		cin>>a>>b>>c;
		while(b)
		{
			if(b%2==0)
			{
				b/=2;
				a=a*a%c;
			}
			else
			{
				b-=1;
				rol=rol*a%c;
				b/=2;
				a=a*a%c;
			}
		}
		cout<<rol<<endl;
   }
	
	return 0;
}
