#include<iostream>
#include<cstdio>
#include<string>
#define int long long
#define maxn 1000005
using namespace std;

int read()
{
	int x=1,res=0;
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

int l=0,tot=0,pd;
string a,cc;

signed main()
{
	getline(cin,cc);
	int len=cc.size();
	for(int i=0;i<len;i++)
	{
//		cout<<a<<endl<<l<<" "<<tot<<endl;
		char c=cc[i];
		if(c=='[') l=0;
		else if(c==']') l=tot;
		else if(c=='{')
		{
			if(l==0) continue;
			l--;
		}
		else if(c=='}')
		{
			if(l==tot) continue;
			l++;
		}
		else if(c=='-') pd=(pd+1)%2;
		else if(c=='=') {
			a.erase(l-1,1);
			tot--;l--;
		}
		else
		{
			if(pd==0) 
			{
				a.insert(l,1,c);
				l++;tot++;
				continue;
			}
			else a[l]=cc[i];
			l++;
		}
	}
	cout<<a<<endl;
	return 0;
}
