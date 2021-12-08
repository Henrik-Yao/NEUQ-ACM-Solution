#include<bits/stdc++.h>
using namespace std;
const int M=1e6+20;
	int n,a[M];
int find(int n,int m)  //找范围内最大的
{
	int ans=n+1;
	for(int i=n;i<=m;i++)
	{
		if(a[n]<a[i])
		{
			ans=i;
			a[n]=a[i];
		}
	}
	return ans;
}
int link(int n,int m)   //预判最哪个能走最远
{
	for(int i=n;i<=m;i++)
	{
		if(a[n]<a[i]+(i-n))
		{
			n=i;
		}
	}
	return n;
}
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	int k=0,t=0; //k为当前所在位置，t为跳的次数
	while(k+a[k]<n-1)   //在当前位再跳一次即可到终点，就结束循环
	{
		int p=a[k];   //记录，find会改变其值
		int m=find(k,k+a[k]);
		k=link(m,p+k);
		t++;
	}
	cout<<t+1<<endl;  //加再跳的一次
	return 0;   
}
