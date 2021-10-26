#include <iostream>
using namespace std;
int main()
{
	int v,t,n,T,m,max=-1000000000;
	cin>>n>>T;
	for(int i=0;i<n;i++)
	{
		cin>>v>>t;
		if(t<=T) m=v;
		else m=v-t+T;
		if(m>max) max=m; 
	}
	cout<<max;
}
