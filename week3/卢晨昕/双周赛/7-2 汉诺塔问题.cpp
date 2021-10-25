#include<bits/stdc++.h>
#define ll long long
#define inf 0x7fffffff
using namespace std;
void han(int n,string a,string b,string c)
{
	if(n==1)
	{
		cout<<a<<"->"<<c<<endl;
	}
	else
	{
		han(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		han(n-1,b,a,c);
	}
}
string a,b,c;
int main()
{
	int n;
	cin>>n;
	cin>>a>>b>>c;
	han(n,a,b,c);
	return 0;
}
