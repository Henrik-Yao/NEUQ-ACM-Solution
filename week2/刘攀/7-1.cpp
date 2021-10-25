#include<bits/stdc++.h>
using namespace std;
void move(int n,string a,string c)
{
	cout<<a<<"->"<<c<<endl;
}
void f(int n,string a,string b,string c) 
{
	if(n==1) 
	{
	    move(n,a,c);
	}    
	else
	{
		f(n-1,a,c,b);
		move(n,a,c);
		f(n-1,b,a,c);
	}
}
int main()
{
	int sum;
	cin>>sum;
	string a,b,c;
	cin>>a>>b>>c;
	f(sum,a,b,c);
}
