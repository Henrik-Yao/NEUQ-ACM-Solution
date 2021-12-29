#include<bits/stdc++.h>
#pragma GCC optimize(1)
using namespace std;
struct ax{
	char sex;
	string fa;
}; 
map<string,ax> p;
int judge(string a,string b)
{
	int i=1,j;
	for(string x=a;!x.empty();x=p[x].fa,i++)
	{
		j=1;
		for(string y=b;!y.empty();y=p[y].fa,j++)
		{
			if(i>=5 &&j>=5)break;
			if(x==y && (i<5||j<5))
			return 0;
		}
	}
	return 1;
}
int main()
{
	cin.sync_with_stdio(false);
	int n,m;
	string a,b,str;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(b[b.length()-1]=='n')
		p[a]={'m',b.substr(0,b.length()-4)};
		else if(b[b.length()-1]=='r')
		p[a]={'f',b.substr(0,b.length()-7)};
		else p[a].sex=b[b.length()-1];
	}
	cin>>m;
	for(int i=0;i<m;i++){
		cin>>a>>str>>b>>str;
		if(p.find(a)==p.end() || p.find(b)==p.end())
			cout<<"NA"<<endl;
		else if(p[a].sex==p[b].sex)
			cout<<"Whatever"<<endl;
		else {
			if(judge(a,b)==1)
			cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
	}
	return 0;
}
