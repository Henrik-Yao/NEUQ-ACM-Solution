#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int judge[500];
int main()
{
	while(getline(cin,s1))
	{
		getline(cin,s2);
		string ans;
		memset(judge,0,sizeof(judge));
		for(int i=0;i<s2.length();i++)
		judge[(int)s2[i]]++;
		for(int i=0;i<s1.length();i++)
		if(judge[(int)s1[i]]==0)
		ans+=s1[i];
		cout<<ans<<endl;
	}
}
