#include<bits/stdc++.h>
using namespace std;
string x;
void getl(int k,int str)
{
	
	while(k--)
	{
		int flag=0;
		for(int i=str+1;;i++)
		{
			if(flag==0)
			{
				if(x[i]==']') break;
				if(x[i]!='[')
				{
					cout<<x[i];
				}
				else 
				{
					flag=1;
					if(x[i+2]>='0'&&x[i+2]<='9')
					{
						getl((x[i+1]-48)*10+x[i+2]-48,i+2);
					}
					else
						getl(x[i+1]-48,i+1);
				}
			}	
			else
			{
				if(x[i]==']')
				{
					flag=0;
				}
				continue;
			}
		}
	}
	return ;
}
int main()
{
	
	cin>>x;
	int flag=0;
	for(int i=0;i<x.size();i++)
	{
		if(flag==0)
		{
			if(x[i]==']')
			{
				continue;
			}
			if(x[i]!='[')
			{
				cout<<x[i];
			}
			else
			{
				flag=1;
				if(x[i+2]>='0'&&x[i+2]<='9')
				{
					getl((x[i+1]-48)*10+x[i+2]-48,i+2);
				}
				else
				getl(x[i+1]-48,i+1);
			}
		}
		else
		{
			if(x[i]==']')
			{
				flag=0;
			}
			continue;
		}
	}
}
