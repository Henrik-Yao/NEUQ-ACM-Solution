#include<iostream>
using namespace std;
int n,start,flag,vis[50001],m[50001];
int tiaoyue(int start)
{
    vis[start]=1;
	if(m[start]==0)
	{
		flag=1;
	}
	if(start+m[start]<n&&vis[start+m[start]]==0)
	{
		tiaoyue(start+m[start]);
	}
	if(start-m[start]>=0&&vis[start+m[start]]==0)
	{
		tiaoyue(start-m[start]);
	}
}
int main()
{
	int i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>m[i];
	}
	cin>>start;
	tiaoyue(start);
	if(flag==1)
	{
		cout<<"True";
	}
	else
	{
		cout<<"False";
	}
	return 0;
}
