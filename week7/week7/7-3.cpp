#include<bits/stdc++.h>
using namespace std;
string x,p,t;
int main()
{
	while(getline(cin,x),getline(cin,p))
	{
		map<char,int> q;
		for(long long i=0;i<p.size();i++)
		{
			q[p[i]]=1;
		}
		for(long long i=0;i<x.size();i++)
		{	
			if(q[x[i]]==1)
			continue;
			else 
			cout<<x[i];
		}		
		cout<<endl;
	}

	return 0;
}
