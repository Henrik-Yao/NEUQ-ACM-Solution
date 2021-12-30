#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int cj;
	char name[25];
}a[50];
bool cmp(stu x,stu y)
{
	if(x.cj!=y.cj)
	return x.cj>y.cj;
	else
	return strcmp(x.name,y.name)<0;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].name>>a[i].cj;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		cout<<a[i].name<<" "<<a[i].cj<<endl;
	}
	return 0;
}
