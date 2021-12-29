#include<bits/stdc++.h>
using namespace std;
const int M=1e5+6;
struct Person
{
	string f;
	char sex;
};
map<string,Person>mp;
bool judge(string a,string b)
{
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			if(a==b)
			return false;
			b=mp[b].f;
		}
		a=mp[a].f;
	}
	return true;
}
int main()
{
	int n,M;
	cin>>n;
	string m,x;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>x;
		if(x.back()=='r')
		mp[m]={x.substr(0,x.length()-7),'f'};
		else if(x.back()=='n')
		mp[m]={x.substr(0,x.length()-4),'m'};
		else
		mp[m].sex=x.back();
	}
	cin>>M;
	while(M--)
	{
		string m1,x1,m2,x2;
		if(mp.find(m1)==mp.end()||mp.find(m2)==mp.end())
		cout<<"NA"<<endl;
		else if(mp[m1].sex==mp[m2].sex)
		cout<<"Whatever"<<endl;
		else
		{
			if(judge(m1,m2))
			cout<<"Yes"<<endl;
			else
			cout<<"No"<<endl;
		}
	}
}
