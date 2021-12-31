#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a[50];
	a[1]=1;a[2]=1;a[3]=2;
	for(int i=4;i<50;i++)
	{
		a[i]=a[i-2]+a[i-1];
	}	
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		cin>>num;
		cout<<a[num]<<endl;
	}
} 
