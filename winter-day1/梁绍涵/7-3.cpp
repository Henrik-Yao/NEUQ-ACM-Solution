#include<bits/stdc++.h>
using namespace std;
int a[1000010];
int main()
{
	int ans,k=0;
	while(cin>>ans)
	{
		a[k++]=ans;
	}
	sort(a,a+k);int temp=1;
	for(int i=0;i<k;i++)
	{
			if(temp==1)
			{
				cout<<a[i];
				temp=0;
			}
			else
			{
				cout<<"->"<<a[i];
			}
	}
	cout<<endl;
	temp=1;
	for(int i=0;i<k;i++)
	{
		
		if(a[i]%2==1)
		{
			if(temp==1)
			{
				cout<<a[i];
				temp=0;
			}
			else
			{
				cout<<"->"<<a[i];
			}
		}
	}
	cout<<endl;
	temp=1;
	for(int i=0;i<k;i++)
	{
		if(a[i]%2==0)
		{
			if(temp==1)
			{
				cout<<a[i];
				temp=0;
			}
			else
			{
				cout<<"->"<<a[i];
			}
		}
	}
}
