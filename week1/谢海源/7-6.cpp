#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,T;
	cin>>n>>T;
	int v,t,m,s=0;
	for(int i=0;i<n;i++)
	{
		cin>>v>>t;
		if(t>T) s=v-(t-T);
		else s=v;
		if(i==0) m=s;
		if(m<s) m=s;
	}
	cout<<m;
    return 0;
}
