#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
void adjust(int a[],int s,int m)
{
	int t=a[s];
	for(int j=2*s;j<=m;j*=2)
	{
		if(j<m&&a[j]<a[j+1]) j++;
		if(t>=a[j]) break;
		a[s]=a[j];
		s=j;
	}
	a[s]=t;//插入
}
void heapsort(int a[],int n)
{
	for(int i=n/2;i>=1;i--) adjust(a,i,n);
	for (int i = 1; i <= n; i++) cout<<a[i]<<" ";//建好堆后输出
	cout<<endl;
	for(int i=1;i<=n-1;i++)//取出堆中元素
	{
		swap(a[1],a[n+1-i]);//取出根结点放最后
		adjust(a,1,n-i);//调整堆
		for(int j=1;j<=n;j++) cout<<a[j]<<" ";
		cout<<endl;
	}
}
int main()
{
	int n;
	int a[maxn]={};
	cin >> n;
	for (int i = 1; i <=n; i++) scanf("%d",&a[i]);
	
	heapsort(a,n);
	return 0;
}