#include<bits/stdc++.h>
using namespace std;
struct person{
	char sex;
	string father;
};
map<string,person>p;
int an(string a,string b)
{
	int j=1;
	for(string A=a;!A.empty();A=p[A].father,j++)
	{
		int k=1;
		for(string B=b;!B.empty();B=p[B].father,k++)
		{
			if(j>=5&&k>=5)
			{
				return 1;
			}
			if(A==B&&(j<5||k<5))
			{
				return 0;
			}			 
		}
	}
	return 1;
}
int main()
{
	int N,M;
	string a,b,c,d;
	cin>>N;
	for(int i=0;i<N;i++)
	{
		cin>>a>>b;
		if(b[b.length()-1]=='n')
		{
			p[a].sex='m';
			p[a].father=b.substr(0,b.size()-4); 
		}
		else if(b[b.length()-1]=='r')
		{
			p[a].sex='f';
			p[a].father=b.substr(0,b.size()-7); 
		}
		else
		{
			p[a].sex=b[b.length()-1];
		}
	}
	cin>>M;
	for(int i=0;i<M;i++)
	{
		cin>>a>>c>>b>>d;
		if(p.find(a)==p.end()||p.find(b)==p.end())
		{
			cout<<"NA"<<endl;
		}
		else if(p[a].sex==p[b].sex)
		{
			cout<<"Whatever"<<endl;
		}
		else
		{
		    if(an(a,b))
		    {
		    	cout<<"Yes"<<endl;
			}
			else
			{
				cout<<"No"<<endl;
			}
		}
	}
	return 0;
}
