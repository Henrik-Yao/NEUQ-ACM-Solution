#include<iostream>
#include<bits/stdc++.h>
using namespace std;
stack<int> q;
int main()
{
	int temp=1;
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='(')
		{
			q.push(1);
		}
		if(a[i]==')')
		{
			int ans;
			ans=q.top();
			if(ans!=1)
			{
				temp=0;
				break;
			}
			else
			q.pop();
		}
		if(a[i]=='[')
		{
			q.push(2);
		}
		if(a[i]==']')
		{
			int ans;
			ans=q.top();
			if(ans!=2)
			{
				temp=0;
				break;
			}
			else
			q.pop();
		}
		if(a[i]=='{')
		{
			q.push(3);
		}
		if(a[i]=='}')
		{
			int ans;
			ans=q.top();
			if(ans!=3)
			{
				temp=0;
				break;
			}
			else
			q.pop();
		}
	}
	if(!q.empty())
	temp=0;
	if(temp==1)
	cout<<"yes";
	else
	cout<<"no";
}
