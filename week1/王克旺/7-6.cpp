#include<iostream>
using namespace std;
int main()
{
	int n,T,max=-10000;
	cin>>n>>T;
	while(n--)
	{
		int v,t;
		cin>>v>>t;
		if (t>T)
		{
			v=v-(t-T);
		}
		if (v>max)
		{
			max=v;
		}
	}
	cout<<max;
	return 0;
} 
