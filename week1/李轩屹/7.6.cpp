#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,T,max=-10000;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		int t,v;
		cin>>v>>t;
		if(T>=t) v=v;
		else v=v-(t-T);
		if(v>max) max=v;
	}
	cout<<max;
	return 0;
}
