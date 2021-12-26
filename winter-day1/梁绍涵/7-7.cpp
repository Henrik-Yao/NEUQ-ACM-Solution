#include<bits/stdc++.h>
using namespace std;
void putstring(string x)
{
	for(int i=x.size()-1;i>=1;i--)
	{
		cout<<x[0]<<x[i];
	}
	cout<<x[0];
	return ;
}
int main()
{
	string a,b;
	cin>>a;
	int temp=1;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='A')
		cout<<"sae";
		if(a[i]=='B')
		cout<<"tsaedsae";
		if(temp==2)
		{
			b+=a[i];
		}
		if(a[i]=='(')
		{
			while(a[++i]!=')')
			{
				b+=a[i];
			}
			putstring(b);
		}
		if(a[i]=='#') break;
	}
}

