#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,d[1000001],site=0,sum=0;//site：当前所在位置，sum：移动数,数据范围在1000000内
	cin>>n;
	for(int i=0;i<n;i++) cin>>d[i];
	n--;//从第一格开始跳，距离-1 
	while(1)
	{
		if(d[site]>=n)
		{
			sum++;break;
		}
		else
		{
			int max1=site;
			for(int i=site+1;i<=site+d[site];i++)
				if((d[i]+i)>(d[max1]+max1)) max1=i;//在范围内寻找终点最远的点 
			n-=max1-site;
			site=max1;
			sum++;
		}
	}
	cout<<sum;
	return 0;
}
