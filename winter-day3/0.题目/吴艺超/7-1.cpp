#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct ax
{
	int x,y,dis;
}a[21000];
int n,e;
bool comp(ax c1,ax c2)
{
		if(c1.x<c2.x) return 1;
		else if(c1.x==c2.x)
		{
			return c1.y<c2.y;
		}
		else return 0;
}
int main()
{
	cin>>n>>e;
	for(int i=1;i<=e;i++)
	{
		int x,y,dis;
		cin>>x>>y>>dis;
		a[i].x=x;
		a[i].y=y;
		a[i].dis=dis;
	}
	sort(a+1,a+e+1,comp);
	for(int i=1;i<=e;i++)
	{
		printf("%d:(%d,%d,%d)",a[i].x,a[i].x,a[i].y,a[i].dis);
		while(a[i+1].x==a[i].x)
		{
			i++;
			printf("(%d,%d,%d)",a[i].x,a[i].y,a[i].dis);
		}
		cout<<endl;
	}
	return 0;
}
