#include<bits/stdc++.h>
#define ll long long
using namespace std;
int z1,z2,z3;
string a;
int main()
{
	getline(cin,a);
	for(int i=0;i<a.length();i++)
	{
		if(a[i]=='(')z1++;
		if(a[i]=='[')z2++;
		if(a[i]=='{')z3++;
		if(a[i]==')')
		{
			if(z1>0)z1--;
			else{
				cout<<"no";
				return 0;
			}
		}
		if(a[i]==']')
		{
			if(z2>0)z2--;
			else{
				cout<<"no";
				return 0;
			}
		}
		if(a[i]=='}')
		{
			if(z3>0)z3--;
			else{
				cout<<"no";
				return 0;
			}
		}
	}
	if(z1==0 && z2==0 & z3==0)
		cout<<"yes";
		else cout<<"no";
	return 0;
}
