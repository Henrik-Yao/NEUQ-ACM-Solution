#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int b[M];
int main()
{
	int n,cnt=0;
	cin>>n;
	n=2*n;
	set<int>a;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.insert(x);
	}
	for(set<int>::iterator i=a.begin();i!=a.end();i++)
	{
		b[++cnt]=*i;
	}
	sort(b+1,b+1+cnt);
	cout<<b[cnt/2];
}
