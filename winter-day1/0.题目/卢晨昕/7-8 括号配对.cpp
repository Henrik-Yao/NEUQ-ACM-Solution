#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
char a[100005];
int top=0;
string x;
int main()
{
	cin>>x;
	for(int i=0;i<x.length();i++)
	{
		if(x[i]=='(')
		{
			a[++top]=x[i];
		}
		else if(x[i]=='[')
		{
			a[++top]=x[i];
		}
		else if(x[i]=='{')
		{
			a[++top]=x[i];
		}
		else if(x[i]==')')
		{
			if(a[top]=='(')top--;
			else 
			{
				cout<<"no";
				return 0;
			}
		}
		else if(x[i]==']')
		{
			if(a[top]=='[')top--;
			else 
			{
				cout<<"no";
				return 0;
			}
		}
		else if(x[i]=='}')
		{
			if(a[top]=='{')top--;
			else 
			{
				cout<<"no";
				return 0;
			}
		}
	}
	if(top==0)cout<<"yes";
	else cout<<"no";
	return 0;
}
