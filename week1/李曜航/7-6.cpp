#include<bits/stdc++.h>
using namespace std;
int n,T;
const int N = 100010;
int t,v;
int main()
{
	int hap = -99999999;
	cin>>n>>T;
	for(int i=1;i<=n;i++)
	{
		cin>>v>>t;
		if(t>T)
			hap = max(hap,v-(t-T));
		else
			hap = max(hap,v);
	}
	cout<<hap;
	
	
	
}