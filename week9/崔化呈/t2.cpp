#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
bool cmp(int l,int r)
{
	return l>r;
}
int main()
{
	int n,m,a[N];
	cin>>n>>m;
	if(m>=n){cout<<n<<endl;return 0;}
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n,cmp);
	int dis[N];
	for(int i=0;i<n-1;i++)
	{
		dis[i]=a[i]-a[i+1]-1;  //一段区间的中间部分，两头依然需要保留 
	}
	sort(dis,dis+n-1,cmp);
	int l=1;
	int tot=a[0]-a[n-1]+1; 
	int now=0;
	while(l<m&&dis[now]>0)
	{
		l++;
		tot-=dis[now];  //剪断
		now++;
	}
	cout<<tot<<endl;
	return 0;
}
