#include <bits/stdc++.h>
using namespace std;
void ans(int n,string a,string b,string c )//a为起点，b为中介，c为终点 
{
	if(n==1)
	cout<<a<<"-->"<<c<<endl;
	else 
	{
		ans(n-1,a,c,b);
		cout<<a<<"-->"<<c<<endl;
	    ans(n-1,b,a,c); 
	}
}
int main()
{
    int n;
    string a,b,c;
    cin>>n;
    cin>>a>>b>>c;
    ans(n,a,b,c);
	return 0;
}
