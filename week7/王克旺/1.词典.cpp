#include<iostream>
#include<string>
#include<map>
using namespace std;
map<string,string>x;
int main()
{
    int m,n;
	string a,b,c;	
	cin>>n>>m;
	while(n--)
	{
		cin>>a>>b;
		x[b]=a;
	}
	while(m--)
	{
		cin>>c;
		if(x.find(c)!=x.end())
		{
			cout<<x[c]<<endl;
		}
		else
		{
			cout<<"eh"<<endl;
		}
	}
	return 0;
}

