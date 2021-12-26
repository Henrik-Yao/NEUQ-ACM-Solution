#include <bits/stdc++.h>
using namespace std;
int main()
{
	string str;
	while(cin>>str)
	{
		int count=0,sum=0,sum1=0,sum2=0;
		for(int i=0;i<str.length();i++)
		{
			if(str[i]=='(')
			{
				if(count<0) 
				{
					sum-=count;
					sum1-=count;
					count=1;
				}
				else count++;
			}
			else count--;
		}
		if(count==0) cout<<"Match"<<'\n';
		else if(count<0) 
		{
			sum-=count;
			sum1-=count;
		}
		else
		{
			sum+=count;
			sum2+=count;
		}
		if(count!=0) 
		{
			cout<<sum<<'\n';
			for(int i=0;i<sum1;i++) cout<<'(';
			cout<<str;
			for(int i=0;i<sum2;i++) cout<<')';
			cout<<'\n'; 
		}
	}
	
	return 0;
}
