#include<bits/stdc++.h>
using namespace std;
int len,w,y;
int main()
{
	string s;
	cin>>s;
	len=s.size();
	w=len/2;
	y=1;
	for(int i=1;i<=w;i++)
	{
		if(s[i]!=s[len-i-1])
		{
			y=0;
			break;
		}
	}
	if(y==1) cout<<"yes"<<endl;
	if(y==0) cout<<"no"<<endl;
	
}
