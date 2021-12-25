#include<bits/stdc++.h>
#define ll long long
using namespace std;
string a;
int main()
{
	while(getline(cin,a))
	{
		int tot=0;
		int len=a.length();
		int l=0,r=0;
		for(int i=0;i<len;i++)
		{
			if(a[i]=='(')
				l++;
			if(a[i]==')')
			{
				if(l>0)l--;
				else r++;
			}
		}
		if(l==0 && r==0)
		{
			cout<<"Match"<<endl;
		}
		else{
			cout<<l+r<<endl;
			for(int i=1;i<=r;i++)
			a='('+a;
			for(int i=1;i<=l;i++)
			a=a+')';
			cout<<a<<endl;
		}
	}
	return 0;
}
