#include<bits/stdc++.h>
using namespace std;
map<string,string>match;
map<string,string>::iterator ans;
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		match[b]=a;
	}
	for(int i=1;i<=m;i++)
	{
		string c;
		cin>>c;
		ans=match.find(c);
		if(ans!=match.end())
		cout<<match[c]<<endl;
		else
		cout<<"eh"<<endl;
	}
}
