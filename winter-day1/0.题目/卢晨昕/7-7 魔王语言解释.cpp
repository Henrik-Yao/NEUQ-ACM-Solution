#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string B="tsaedsae";
string A="sae";
string a;
string ans;
string fan(int l,int r)
{
	string la;
	for(int i=r;i>l;i--)
	{
		la+=a[l];
		la+=a[i];
	}
	la+=a[l];
	return la;
}
int main()
{
	cin>>a;
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='A')ans+=A;
		else if(a[i]=='B')ans+=B;
		else if(a[i]=='(')
		{
			int l=i,r;
			for(int j=i;j<=a.length();j++)
			{
				if(a[j]==')')
				{
					r=j;
					break;
				}
			}
			ans+=fan(l+1,r-1);
			i=r;
		}
	}
	cout<<ans;
	return 0;
}
