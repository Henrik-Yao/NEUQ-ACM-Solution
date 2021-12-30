#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int INF = 1e6;
int a[maxn],b[maxn],sum=0;
int n,m;
//最大化的最小值
bool check(int x)
{
	int sum=1;//默认选第一间
	int k=x+a[0];//贪心默认选第一间小屋
	for(int i=1;i<n;i++)
	{
		if(a[i]>=k)//大于这个最小距离
		{
			sum++;//继续放牛
			k=a[i]+x;//加上距离x
		}
		if(sum>=m) return 1;//若满足大于m，则x可继续在大区间二分求答案
	}
	return 0;
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n);
	int l=a[0],r=a[n-1];
	while(l<=r)//对奶牛间的距离进行二分
	{
		int x=(l+r)>>1;
		if(check(x)) l=x+1;//右侧二分
		else r=x-1;//左侧二分
	}
	cout<<r;
	return 0;
}