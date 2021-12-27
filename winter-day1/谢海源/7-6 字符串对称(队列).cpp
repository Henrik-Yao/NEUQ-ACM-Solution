#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	cin>>s;
	int n=s.size();
	int f=1;
	for(int i=0;i<n;i++)
	{
		if(s[i]==s[n-1-i]) continue;
		f=0;
		break;
	}
	if(f) cout<<"yes";
	else cout<<"no";
	return 0;
}