#include<bits/stdc++.h>
#include<set>
using namespace std;
set<int>s[100];
int main()
{
	int n,m,q,num=0;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(!s[num].count(a)&&!s[num].count(b))
		{
			num++;
			s[num].insert(a);
			s[num].insert(b);
		}
		else if(!s[num].count(a))
		{
			s[num].insert(a);
		}
		else if(!s[num].count(b))
		{
			s[num].insert(b);
		}
	}
	for(int i=0;i<q;i++)
	{
		int c,d;
		cin>>c>>d;
		int flag=0;
	    for(int j=1;j<=num;j++)
		{
		    if(s[j].count(c)&&s[j].count(d))
			{
			    flag=1;
	    	}
	    }
	    if(flag)
	    {
	    	cout<<"In the same gang."<<endl;
	    }
	    else
	    {
	    	cout<<"In different gangs."<<endl;
	    }
    }
	cout<<num<<endl;
	return 0;
}
