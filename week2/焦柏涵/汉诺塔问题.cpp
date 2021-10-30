#include <iostream>
#include <cstring>
using namespace std;
int n;
string a[4];
int han(int n,int p,int q)
{
	if(!n) return 0;
	int w;
	for(int i=1;i<=3;i++)
	{
		if(i!=p&&i!=q) w=i;
	}
	han(n-1,p,w);
	cout<<a[p]<<"->"<<a[q]<<endl;
	han(n-1,w,q);
}
int main()
{
	cin>>n>>a[1]>>a[2]>>a[3];
	han(n,1,3);
}
