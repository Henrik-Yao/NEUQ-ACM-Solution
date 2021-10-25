#include<iostream>
using namespace std;
const int maxn=1e5+10;
struct point
{
	string s;
	int p;
}a[maxn];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].p>>a[i].s;
	}
	int p=0;
	int op,l;
	while(m--)
	{
		cin>>op>>l;
		if(op!=a[p].p)
		{
			p=(p+l)%n;
		}
		else
		{
			p=(p-l+n)%n;
		}
	}
	cout<<a[p].s;
}
