#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read()
{
	char ch=getchar();
	int x=0,f=1;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-f;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		x=x*10+(ch^48),ch=getchar();
	return x*f;
} 
map<string,string> q;
int m,n;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		string a,b;
		cin>>a>>b;
		q[b]=a;
	}
	for(int i=1;i<=m;i++)
	{
		string a;
		cin>>a;
		if(q.find(a)==q.end())
			cout<<"eh"<<endl;
		else cout<<q[a]<<endl;
	}
	return 0;
}
