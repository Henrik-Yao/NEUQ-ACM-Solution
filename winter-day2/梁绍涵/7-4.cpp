#include<bits/stdc++.h>
using namespace std;
int f[2000];
int find(int p)
{
	if(f[p]!=p)
	{
		f[p]=find(f[p]);
		return find(f[p]);
	}
	else
	return p;
}
void make(int t1,int t2)
{
	f[t1]=t2;
	return;
}
int main()
{
	int n,m,q;
	cin>>n>>m>>q;
	for(int i=1;i<=n;i++)
	f[i]=i;
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		make(find(x),find(y));
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)!=find(y))
		cout<<"In different gangs."<<endl;
		else
		cout<<"In the same gang."<<endl;
		
	}
	sort(f+1,f+n+1);
	int sum=1;
	for(int i=2;i<=n;i++)
	{
		if(f[i]!=f[i-1])
		sum++;
	}
	cout<<sum;
} 
