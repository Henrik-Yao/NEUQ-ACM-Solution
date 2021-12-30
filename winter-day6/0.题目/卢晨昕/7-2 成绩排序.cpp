#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f

using namespace std;
struct node
{
	int point;
	string name;
}e[25];
int n;
bool cmp(node a,node b)
{
	if(a.point>b.point)return true;
	else if(a.point<b.point)return false;
	else
	{
		return a.name<b.name;
	}
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i].name>>e[i].point;
	}
	sort(e+1,e+1+n,cmp);
	for(int i=1;i<n;i++)
	{
		cout<<e[i].name<<" "<<e[i].point<<endl;
	}
	cout<<e[n].name<<" "<<e[n].point;
	return 0;
}

