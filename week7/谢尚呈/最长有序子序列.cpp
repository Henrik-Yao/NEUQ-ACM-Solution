#include<iostream>
using namespace std;

int ori[1000], has[1000];
int n, total;

void solve(int it)
{
	if(it==0)	has[it]=1;
	else
	{
		int maxn=0;
		for(int i=it-1; i>=0; i--)
		if(ori[i]<ori[it])
		if(has[i]>maxn)	maxn=has[i];
		has[it]=maxn+1;
	}
	if(it==n-1)	return;
	solve(it+1);
}

int main()
{
	int times;
	cin>>times;
	for(int z=0; z<times; z++)
	{
		for(int i=0; i<1000; i++)	ori[i]=has[i]=0;
		total=0;
		cin>>n;
		for(int i=0; i<n; i++)	cin>>ori[i];
		solve(0);
		for(int i=0; i<n; i++)
		if(has[i]>total)	total=has[i];
		cout<<total;
		cout<<endl;
		if(z!=times-1)	cout<<endl;
	}
	return 0;
}
