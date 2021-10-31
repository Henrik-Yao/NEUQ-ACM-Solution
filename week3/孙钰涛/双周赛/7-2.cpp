#include<iostream>
#include<string>
using namespace std;

void move(string here,string to,string there,int n)
{
	if(n==1) 
	{
		cout<<here<<"->"<<there<<endl;
		return ;
	}
	move(here,there,to,n-1);
	cout<<here<<"->"<<there<<endl;
	move(to,here,there,n-1);
	return ;
}

int main()
{
	int n;
	string a,b,c;
	cin>>n>>a>>b>>c;
	move(a,b,c,n);
	return 0; 
}