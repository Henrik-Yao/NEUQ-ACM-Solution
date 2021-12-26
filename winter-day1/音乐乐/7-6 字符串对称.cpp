#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,s1;
	cin>>s;
	s1=s;
	reverse(s.begin(),s.end());
	if(s1==s)
	cout<<"yes"<<endl;
	else
	cout<<"no"<<endl;
	return 0;
}
