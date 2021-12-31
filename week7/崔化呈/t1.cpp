#include<bits/stdc++.h>
using namespace std;
int n,m;
map<string,string>link;
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		string a,b;
		cin>>a>>b;
		link[b]=a;
	}
	for(int i=0;i<m;i++)
	{
		string c;
		cin>>c;
		if(link[c].empty()){cout<<"eh"<<endl;}
		else{cout<<link[c]<<endl;}
	}
	return 0;
}
