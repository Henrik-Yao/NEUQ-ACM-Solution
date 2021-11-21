#include <bits/stdc++.h>
using namespace std;
map<string,int>mp;
char hhash(string s)
{
	int sum=0;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]>='A'&&s[i]<='Z')
		{
			s[i]=s[i]+32;
		}
		if(s[i]>='0'&&s[i]<='9')
		{
			sum=sum+s[i]-'0';
		}
		else
		sum=sum+s[i]-'a'+10;
	}
	sum=sum%36;
	if(sum<10)
	return sum+'0';
	else return sum-10+'a';
}
string Hash(string s)
{
	string fh="0000";
	int n[5]={0};
	for(int i=0;i<s.size()%4;i++)
	{
		n[i]++;
	}
	int j=0;
	for(int i=0;i<4;i++)
	{
		n[i]=n[i]+s.size()/4; 
		string s1=s.substr(j,n[i]);
		j=j+n[i];
		fh[i]=hhash(s1);
	}
	return fh;
}
int n;
struct ty
{
	string name;
	string mima;
	string hash;
}a[1001],b[1001];

int main()
{
	cin>>n;
	int t=0;
	for(int i=0;i<n;i++)
	{
		char op;
		cin>>op;
		cin>>a[i].name;
		cin>>a[i].mima;
		a[i].hash=Hash(a[i].mima);
		if(op=='R')
		{
			if(mp[a[i].name]!=0)
			{
				cout<<"Repeated!"<<endl;
			}
			else 
			{
				b[t].name=a[i].name;
				b[t].mima=a[i].mima;
				b[t].hash=a[i].hash;
				t++;
				mp[a[i].name]=1;
				cout<<"Signed!"<<endl;
			}
		}
		if(op=='L')
		{
			if(mp[a[i].name]==0)
			{
				cout<<"Failed!"<<endl;
			}
			else
			{
			for(int j=0;j<=t;j++)
			{
				if(a[i].name!=b[j].name)
				{
					continue;
				}
				else if(a[i].name==b[j].name)
				{
				    if(a[i].mima==b[j].mima)
				    {
				 	cout<<"Success!"<<endl;
				    }
				    else
				    {
				    	if(a[i].hash==b[j].hash)
				    	{
				    		cout<<"Attention!"<<endl;
						}
					     if(a[i].hash!=b[j].hash)
						{
							cout<<"Failed!"<<endl;
						}
				    }
					break;
			    }
			}
		    }
	    }
	}
	return 0;
}
