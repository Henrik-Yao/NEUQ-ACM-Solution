#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
string a;
string b;
int main()
{
	
	while(getline(cin,a))
	{
		int v[10005];
		memset(v,0,sizeof(v));
		getline(cin,b);
		for(int i=0;i<b.length();i++)v[int(b[i])]=1;
		for(int i=0;i<a.length();i++)
		{
	  		if(v[int(a[i])]==0)cout<<a[i];
		}
		cout<<endl;
		a.clear();
		b.clear();
	}
	return 0;
}
