#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,pair<string,string> >m;
struct User
{
	char ch;
	string name;
	string password;
	string hash;
}user[1001];
char hx(string s)
{
	int sum=0,len=s.length();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			sum=sum+s[i]-'0';
		}
		else if(s[i]>='a'&&s[i]<='z')
		{
			sum=sum+s[i]-'a'+10;
		}
		else
		{
			sum=sum+s[i]-'A'+10;
		}
	}
	sum=sum%36;
	if(sum<10)
	{
		return sum+'0';
	}
	else
	{
		return sum-10+'a';
	}
}
string Hash(string s)
{
	int i,j=0,len=s.size(),count[5]={0};
	char x;
	string str,haxi="0000";
	for(int i=0;i<4;i++)
	{
	    count[i]=count[i]+len/4;
	    if(i<len%4)
	    {
	    	count[i]++;
		}	
	}
	for(i=0;i<4;i++)
	{		
		str=s.substr(j,count[i]);
		j=j+count[i];
		x=hx(str);
		haxi[i]=x;
	}
	return haxi;
}
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>user[i].ch>>user[i].name>>user[i].password;
		user[i].hash=Hash(user[i].password);
		if(user[i].ch=='R')
		{
			if(m.find(user[i].name)!=m.end())
			{
				cout<<"Repeated!"<<endl;
			}
			else
			{
				m[user[i].name].first=user[i].password;
				m[user[i].name].second=user[i].hash;
				cout<<"Signed!"<<endl;
			}
		}
		else if(user[i].ch=='L')
		{
			if(m.find(user[i].name)==m.end())
			{
				cout<<"Failed!"<<endl;
			}
			else
			{
				if(m.find(user[i].name)->second.first==user[i].password)
				{
					cout<<"Success!"<<endl;
				}
				else
				{
					if(m.find(user[i].name)->second.second==user[i].hash)
					{
						cout<<"Attention!"<<endl;
					}
					else
					{
						cout<<"Failed!"<<endl;
					}
				}
			}
		}
	}		
	return 0;
}
