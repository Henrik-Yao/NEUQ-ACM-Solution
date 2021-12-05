#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
map<string,string>p;
map<string,int>pp;
int n,m;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		p[b]=a;
		pp[b]=1;
	}
	for(int i=1;i<=m;i++)
	{
		string a;
		cin>>a;
		if(pp[a]==1)cout<<p[a]<<endl;
		else cout<<"eh"<<endl;
	}
	return 0;
}
