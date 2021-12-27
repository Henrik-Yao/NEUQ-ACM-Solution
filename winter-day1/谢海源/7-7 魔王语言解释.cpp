#include<bits/stdc++.h>
using namespace std;
stack<char>lan;
int main()
{
	string s,B="tsaedsae",A="sae",s2,s3;
	getline(cin,s);
	int n=s.size();
	for(int i=0;i<n;i++)
	{
		if(s[i]=='B') s2+=B;
		else if(s[i]=='A') s2+=A;
		else if(s[i]!='#') s2+=s[i];	
	}
	int n2=s2.size();
	for(int i=0;i<n2;i++)
	{
		if(s2[i]=='(')
		{
			char t=s2[++i];
			int l=i,r=i;
			while(s2[r]!=')') r++;
			r--;
			for(int j=r;j>l;j--)
			{
				s3=s3+t+s2[j];
			}
			s3+=t;
			i=r+1;
		}
		else s3+=s2[i];
	}
	cout<<s3<<endl;
	return 0;
}