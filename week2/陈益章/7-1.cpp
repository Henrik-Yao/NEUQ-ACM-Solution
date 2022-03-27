#include<iostream>
#include<cstring>
using namespace std;
void h(int n,char a[],char b[],char c[])
{
	if (n==1)
	cout<<a<<"->"<<c<<endl;
	else
	{
		h(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		h(n-1,b,a,c);
	}
}
int main()
{
    int n;
char a[999],b[999],c[999];
	cin>>n;
	cin>>a>>b>>c;
	h(n,a,b,c);
	return 0;
}
