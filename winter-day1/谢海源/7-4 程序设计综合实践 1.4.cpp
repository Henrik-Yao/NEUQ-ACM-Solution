#include<bits/stdc++.h>
using namespace std;
int b[101]={},n2=0;
void Split(int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(a[i]%2==0)
		{
			b[n2++]=a[i];
			a[i]=0;
		}
	}
}
int main()
{
	int a[101]={};
	int n=0;
	while(cin>>a[n]) n++;
	sort(a,a+n);
	//输出
	for(int i=0;i<n-1;i++)
	{
		cout<<a[i]<<"->";
	}
	cout<<a[n-1]<<endl;
	//
	Split(a,n);
	int f=1;
	for(int i=0;i<n-1;i++)
	{
		if(a[i])
		{
			if(f==1)
			{
				cout<<a[i];
				f=0;
			}
			else cout<<"->"<<a[i];
		}
	}
	cout<<endl;
	f=1;
	for(int i=0;i<n2;i++)
	{
		if(f==1)
		{
			cout<<b[i];
			f=0;
		}
		else cout<<"->"<<b[i];
	}
	return 0;
}