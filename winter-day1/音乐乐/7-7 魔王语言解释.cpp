#include<bits/stdc++.h>
using namespace std;

const string A="sae";
string B='t'+A+'d'+A;

int main()
{
	string s,ans;
	getline(cin,s);
	for(int i=0;s[i]!='#';i++)
	{
		if(s[i]=='B')
		ans+=B;
		if(s[i]=='A')
		ans+=A;
		if(s[i]=='(')
		{
			int l=i+1;
			i++;
			char head=s[i];
			ans+=head;
			while(s[i]!=')')
			i++;
			int r=i;
			while(i!=l+1)
			{
				i--;
				ans+=s[i];
				ans+=head;
			}
			i=r;
		}
	}
	cout<<ans;
	return 0;
}
