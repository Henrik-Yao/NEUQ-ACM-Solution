#include<bits/stdc++.h>
using namespace std;
const int M=1e6;
struct pa
{
	int a;
	int b;
}p[M];
bool cmp(pa n,pa m)
{
	return n.b<m.b;    //依照结束时间进行排序，优先进行最早结束的活动
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>p[i].a>>p[i].b;
		}
		sort(p,p+n,cmp);
		int ans=1;   //至少参加了一个，ans为参加的活动数
		int j=0;    //j代表当前进行的活动
		for(int i=1;i<n;i++)
		{
			if(p[i].a>=p[j].b)    //找当前活动结束后紧接的活动参加
			{
				ans++;
				j=i;
			}
		}
		cout<<n-ans<<endl;
	}
}
