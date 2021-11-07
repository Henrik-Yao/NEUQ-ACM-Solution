#include<iostream>
using namespace std;

long long mem[1000];

void solve(int lim, int now)
{
	if(now>lim)	return;
	mem[now]=mem[now-1]+mem[now-2];
	solve(lim, now+1);
	return;
}

int main()
{
	int *arr, n, max=0;
	cin>>n;
	arr=new int[n];
	
	for(int i=0; i<n; i++)
	{
		cin>>arr[i];
		if(arr[i]>max)	max=arr[i];
	}
	mem[1]=1;
	mem[2]=1;
	solve(max+1, 3);
	
	for(int i=0; i<n; i++)
	{
		if(arr[i]==0)	cout<<0;
        else if(arr[i]==1)   cout<<0;
		else	cout<<mem[arr[i]];
		if(i!=n-1)	
		cout<<endl;
	}
	return 0;
}
