#include<bits/stdc++.h>
using namespace std;
map<string,string>link;
int haash(string s)
{
	int num[110];
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]>='0'&&s[i]<='9'){num[i]=s[i]-'0';}
		if(s[i]>='A'&&s[i]<='Z'){num[i]=s[i]-'A'+10;}
		if(s[i]>='a'&&s[i]<='z'){num[i]=s[i]-'a'+10;}
	}
	int l[4],mod=len%4;
	for(int i=0,j=mod;i<4;i++,j--)
	{
		if(j>0){l[i]=len/4+1;}
		else{l[i]=len/4;}
	}
	int s1=0,s2=0,s3=0,s4=0;
	for(int i=0;i<l[0];i++){s1+=num[i];s1%=36;}
	for(int i=l[0];i<l[0]+l[1];i++){s2+=num[i];s2%=36;}
	for(int i=l[0]+l[1];i<l[0]+l[1]+l[2];i++){s3+=num[i];s3%=36;}
	for(int i=l[0]+l[1]+l[2];i<len;i++){s4+=num[i];s4%=36;}
	return ((s1*36+s2)*36+s3)*36+s4;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string name,pass;
		char o;
		cin>>o>>name>>pass;
		if(o=='R')
		{
			if(link[name]=="")
			{
				link[name]=pass;
				cout<<"Signed!"<<endl;
			}
			else{cout<<"Repeated!"<<endl;}
			
		}
		else
		{
			if(link[name]==pass){cout<<"Success!"<<endl;}
			else
			{
				int cor=haash(link[name]);
				int temp=haash(pass);
				if(temp==cor){cout<<"Attention!"<<endl;}
				else{cout<<"Failed!"<<endl;}
			}
		}
	}
	return 0;
}
