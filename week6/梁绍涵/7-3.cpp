#include<bits/stdc++.h>
using namespace std;
int n;
typedef pair<string,string> q;
map<string,q> p;
string hash1(string a)
{
	int len=a.size();
	int m=len%4,aver=len/4;
	int str=0,fin=4-m;
	char hx[4];char j;int f=0;
	while(m--)
	{
		int sum=0;
		for(int i=str;i<str+aver+1;i++)
		{
			if(a[i]>='0'&&a[i]<='9') sum+=a[i]-48;
			else if(a[i]>='a'&&a[i]<='z') sum+=a[i]-97+10;
			else if(a[i]>='A'&&a[i]<='Z') sum+=a[i]-65+10;
		}
		sum=sum%36;
		if(sum<=9)
		{
			j=sum+48;
			hx[f++]=j;
		}
		if(sum>=10)
		{
			j=sum-10+97;
			hx[f++]=j;
		}
		str=str+aver+1;
	}
	while(fin--)
	{
		int sum=0;
		for(int i=str;i<str+aver;i++)
		{
//			cout<<a[i];
			if(a[i]>='0'&&a[i]<='9') sum+=a[i]-48;
			else if(a[i]>='a'&&a[i]<='z') sum+=a[i]-97+10;
			else if(a[i]>='A'&&a[i]<='Z') sum+=a[i]-65+10;
		}
		sum%=36;
		if(sum<=9)
		{
			j=sum+48;
			hx[f++]=j;
		}
		else
		{
			j=sum-10+97;
			hx[f++]=j;
		}
		str+=aver;
//		cout<<"?"<<ans;
	}
	return hx;
}
int main()
{//cout<<hash1("AAAABB23BBBB");
	cin>>n;
	
//	cout<<hash1("0km6trlhdcwca");
	
	while(n--)
	{
		char x;
		string id,lk;
		cin>>x>>id>>lk;
		if(x=='L')
		{
			if(p.find(id)==p.end())
			{
				cout<<"Failed!"<<endl;
				continue;
			}
			else if(p.find(id)!=p.end()&&lk!=p[id].first)
			{	
				if(hash1(lk)==p[id].second)
				{
					cout<<"Attention!"<<endl;
					continue;
				}
				else
				{
					cout<<"Failed!"<<endl;
					continue;
				}
			}
			else if(p.find(id)!=p.end()&&lk==p[id].first)
			{
				cout<<"Success!"<<endl; 
			}
		}
		else
		{
			if(p.find(id)!=p.end())
			{
				cout<<"Repeated!"<<endl;continue;
			}
			else
			{
				p[id].first=lk;
				p[id].second=hash1(lk);
				cout<<"Signed£¡"<<endl;
				continue;
			}
		}
	}
}
