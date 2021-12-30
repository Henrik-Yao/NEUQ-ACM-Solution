#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[200];
	memset(a,0,sizeof(a));
	for(int i=0;i<n;i++)
	{
		int num;
		cin>>num;
		a[num]++;
	}
	for(int i=0;i<=50;i++)
	{
		if(a[i]!=0)
		cout<<i<<":"<<a[i]<<endl;
	}
}
