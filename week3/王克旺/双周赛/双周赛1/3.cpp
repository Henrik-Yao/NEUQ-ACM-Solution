#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n;	
	while(cin>>n)
	{
	    long long m=1;
		int i;
		for(i=1;i<=n;i++)
		{
			m=m*3;
		}
		m=m-1;
		cout<<m<<endl;
	}
	return 0;
}
