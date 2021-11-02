#include<iostream>
#include<string.h>
using namespace std;
void yidong(int i,string str1,string str2)
{
	cout<<str1<<"->"<<str2<<endl;
}
int tower(int i,int n,string str1,string str2,string str3)
{
	if(n==1)
	{
		yidong(i,str1,str3);
	}
	else
	{
		tower(i,n-1,str1,str3,str2);
		yidong(i,str1,str3);
		tower(i,n-1,str2,str1,str3);
	}
}
int main()
{
	int n,i=0;
	string a,b,c;
	cin>>n;
	cin>>a>>b>>c;
	tower(i,n,a,b,c);
}
