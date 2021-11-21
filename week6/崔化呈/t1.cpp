#include<bits/stdc++.h>
using namespace std;
string str,par;
int nextt[100010],ans=0;
void getnext()
{
	int i=0,j=-1;
	nextt[0]=-1;
	while(i<par.size())
	{
		if(j==-1||par[i]==par[j])
		{
			i++;j++;
			nextt[i]=j;
		}
		else{j=nextt[j];}
	}
}
void kmp()
{
	int i=0,j=0;
	while(i<str.size())
	{
		if(j==-1||str[i]==par[j])
		{
			i++;j++;
		}
		else{j=nextt[j];}
		if(j==par.size())
		{
			ans++;
		}
	}
}
int main()
{
	cin>>str>>par;
	getnext();
	kmp();
	cout<<ans;
	return 0;
}
