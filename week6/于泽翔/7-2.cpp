#include <bits/stdc++.h>
using namespace std;
int n;
char opt;
string id, password;

map<string, string> rp;
map<string, vector<int> > has;

vector<int> get_has(string s)
{
	int l_s=s.size(), a, l, sum, pos=0;
	vector<int> num, ans;
	
	for(int i=0; i<l_s; i++)
		if(s[i]>='A'&&s[i]<='Z')
			s[i]+=32;
	for(int i=0; i<l_s; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
			a=s[i]-'0';
		else
			a=s[i]-'a'+10;
		num.push_back(a);
	}
	for(int i=0; i<10; i++)
		num.push_back(0);
	
	l=l_s/4;
	sum=l_s;
	for(int k=0; k<4; k++)
	{
		int nn=0;
		if(sum<s.size())
		{
			sum++;
			l++;
		}
		for(int i=pos; i<=l+pos-1; i++)
			nn+=num[i];
		ans.push_back(nn%36);
		pos+=l;
	}
	return ans;
}
int main(void)
{
	cin>>n;
	while(n--)
	{
		cin>>opt>>id>>password;
		if(opt=='R')
			if(rp.count(id))
				puts("Repeated!");
			else
			{
				rp[id]=password;
				has[id]=get_has(password);
				puts("Signed!");
			}
		else
		{
			if(!rp.count(id))
				puts("Failed!");
			else if(rp[id]==password)
				puts("Success!");
			else if(has[id]==get_has(password))
				puts("Attention!");
			else
				puts("Failed!");
		}
	}
	
	return 0;
}