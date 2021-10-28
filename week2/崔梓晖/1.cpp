#include <bits/stdc++.h>
using namespace std;
int n;
string a,b,c;
void hnt(int n,string a,string c,string b)
{
	if(n==0)
	{
		return;
	}
	else
	{
		hnt(n-1,a,b,c);
		cout<<a<<"->"<<c<<endl;
		hnt(n-1,b,c,a);
		
	}
}
int main()
{
	cin>>n;
	cin>>a;
	cin>>b;
	cin>>c;
	hnt(n,a,c,b);
	return 0;
}
