#include<bits/stdc++.h>
using namespace std;
queue<int> q;
int main()
{
	string a;
	while(cin>>a)
	{
		int sum1=0,sum2=0;
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='(')
			q.push(1);
			else
			{
				if(!q.empty())
				{
					q.pop();
				}
				else
				{
					sum1++;
				}
			}
		}
		while(!q.empty())
		{
			sum2++;
			q.pop();
		}
		if(sum1==0&&sum2==0)
		cout<<"Match"<<endl;
		else
		{
			cout<<sum1+sum2<<endl;
			for(int i=0;i<sum1;i++) cout<<"(";
			cout<<a;
			for(int i=0;i<sum2;i++) cout<<")";
			cout<<endl;	
		} 
	}
	
}
