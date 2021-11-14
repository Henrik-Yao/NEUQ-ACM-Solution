#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	int t;
	long long  a, b, c;
	cin>>t;
	
	while(t--)
	{
		cin>>a>>b>>c;
		long long  w=1;
		
		while(b>0)
		{
			if(b%2==1)
			{
				w*=a;
				w%=c;
			}
			a*=a;
            a%=c;
			b/=2;
		}
		cout<<w<<endl;
	}
	 
	
	return 0;
}