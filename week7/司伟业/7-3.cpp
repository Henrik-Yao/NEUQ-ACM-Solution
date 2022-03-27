#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<map>
using namespace std;

int read()
{
	int res=0,x=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
		x=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		res=res*10+(c-'0');
		c=getchar();
	}
	return res*x;
}

map<string,int>q;
int len1,len2;

int main()
{
	string a,b,c;
	while(getline(cin,a))
	{
		q.clear();
		getline(cin,b);
		len1=a.size();len2=b.size();
		for(int i=0;i<len2;i++)
		{
			c=b[i];
			q[c]=1;
		}
		for(int i=0;i<len1;i++)
		{
			c=a[i];
			if(q[c]) continue;
			else cout<<a[i];
		}
		puts("");
	}
	return 0;
}

