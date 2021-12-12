#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++) cin>>a[i];
	int dis=1,count=0;
	while(1)
	{
		if(dis+a[dis-1]>=n)
		{
			 cout<<count+1;
			 break;
		}
		int max=dis;
		for(int i=dis;i<a[dis-1]+dis;i++) 
		{
			if(a[i-1]+i>a[max-1]+max&&a[i-1]+i>a[dis-1]+dis+a[a[dis-1]+dis-1]) max=i;
		}
		if(dis==max) dis+=a[dis-1],count++;
		else dis=max,count++;
	}
	return 0;
} 
