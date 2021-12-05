#include <bits/stdc++.h>
using namespace std;
struct ty
{
	string qian;
	string hou;
}a[10001];
int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].hou;
		cin>>a[i].qian;
	}
	for(int i=1;i<=m;i++)
	{
		string b;
		int t=0;
		cin>>b;
		for(int j=1;j<=n;j++)
		{
			if(a[j].qian!=b)
			{
				t++;
				continue;
			}
			if(a[j].qian==b)
			{
				cout<<a[j].hou<<endl;
				break;
			}
		}
		if(t==n)
		{
			cout<<"eh"<<endl;
		}
	}
	return 0;
}
