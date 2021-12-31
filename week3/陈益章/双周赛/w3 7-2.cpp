#include<iostream>
using namespace std;
void f(int n,string a,string b,string c)
{
	if (n==1)
	cout<<a<<"->"<<c<<endl;
	else
	{
		f(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		f(n-1,b,a,c);
	}
}
int main()
{
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	f(n,a,b,c);
	return 0;
 } 
