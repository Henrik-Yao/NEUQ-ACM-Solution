#include<bits/stdc++.h>
using namespace std;
string s;
void jys(int n,int m)
{ 
	int i,flag;
	while(n--)
	{
		flag=0;
		for(i=m+1;;i++)
		{
			if(flag==0)
			{
				if(s[i]=='[')
				{
					flag=1;
					if(s[i+2]>='0'&&s[i+2]<='9')
					{
						jys((s[i+1]-48)*10+s[i+2]-48,i+2);
					}
					else
						jys(s[i+1]-48,i+1);
				}
				else if(s[i]==']')
				{
					break;
				}
				else
				{
					cout<<s[i];
				}
			}	
			else
			{
				if(s[i]==']')
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
	int i,flag=0;
	cin>>s;
	for(i=0;i<s.size();i++)
	{
		if(flag==0)
		{
			if(s[i]=='[')
			{
				flag=1;
				if(s[i+2]>='0'&&s[i+2]<='9')
				{
					jys((s[i+1]-48)*10+s[i+2]-48,i+2);
				}
				else
				{
					jys(s[i+1]-48,i+1);
				}				
			}
			else if(s[i]==']')
			{
				continue;
			}			
			else
			{
				cout<<s[i];
			}
		}
		else
		{
			if(s[i]==']')
			{
				flag=0;
			}
			continue;
		}
	}
}
