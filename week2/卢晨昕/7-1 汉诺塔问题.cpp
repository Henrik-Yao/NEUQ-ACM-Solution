#include<bits/stdc++.h>
using namespace std;

void hannoi(int n,string a,string b,string c)
{
	if(n==1)
	{
		cout<<a<<"->"<<c<<endl;
	}
	else
	{
		hannoi(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		hannoi(n-1,b,a,c);
	}
}
int main()
{
    int n;
    string a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	hannoi(n,a,b,c);
	return 0;
}
