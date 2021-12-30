#include<bits/stdc++.h>
using namespace std;
struct ax{
	string a;
	int sum;
}a[50];
int n;
bool comp(ax aa, ax bb)
{
	if(aa.sum>bb.sum)
	return 1;
	if(aa.sum==bb.sum)
	{
		if(aa.a.compare(bb.a)>0)return 0;
		else return 1;
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].a>>a[i].sum;
	}
	sort(a+1,a+n+1,comp);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].a<<" "<<a[i].sum<<endl;
	}
	return 0;
}
