#include<bits/stdc++.h>
using namespace std;
string str[1010],par;
int nextt[1010];

void getnext(string s)
{
	int i=0,j=-1;
	nextt[0]=-1;
	while(i<par.size())
	{
		if(j==-1||par[i]==par[j])
		{
			i++;j++;
			nextt[i]=j;
		}
		else{j=nextt[j];}
	}
}
int kmp(string s)
{
	int i=0,j=0;
	while(i<s.size())
	{
		if(j==-1||par[j]==s[i])
		{
			i++;j++;
		}
		else{j=nextt[j];}
		if(j==par.size()){return 1;}
		
	}
	return 0;
}
int main()
{
	char c;
	int n=0;
	while(c=getchar())
	{
		if(c=='\n'){break;}
		else if(c>='a'&&c<='z'){str[n]+=c;}
		else if(c>='A'&&c<='Z'){str[n]+=tolower(c);}
		else if(c=='\0'){continue;}
		else{n++;}
	}
	cin>>par;
	for(int i=0;i<par.size();i++)
	{
		par[i]=tolower(par[i]);
	}
	getnext(par);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		if(str[i][0]=='\0'){continue;}
		ans+=kmp(str[i]);
	}
	cout<<ans;
	return 0;
}
