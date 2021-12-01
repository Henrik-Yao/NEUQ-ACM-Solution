#include<bits/stdc++.h>
using namespace std;
int a[1000010];

int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
		cin>>a[i];
	n--;
	int step=0;
	int fur=0,now=0,temp=0;
	while(1)
	{
		fur=0;
		if(a[now]>=n)
		{
			step++;
			break;
		}
		temp=now+a[now];
		for(int i=now+1;i<=now+a[now];i++)
			if(a[i]>=a[temp])
				temp=i;
		fur=temp+a[temp];
		for(int i=temp+1;i<=now+a[now];i++)
		{
			if(i+a[i]>fur)
			{
				fur=i+a[i];
				temp=i;
			} 
		}
		step++;
		n-=(temp-now);
		now=temp;
	}
	cout<<step;
	return 0;
}
