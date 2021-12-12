## 7-1

​	通过计算能够参加的最大活动数，计算出最小失约。

​	先将活动按照结束时间的先后排序，如果一个活动的结束时间比下一个活动的开始时间早，那么他就可以参加	下一个活动。按照这个方法即可利用贪心的思想求出参加的最大活动数。

```cpp
#include<bits/stdc++.h>
using namespace std;
int t;
struct p
{
	int str,end;
}a[10000];
bool cmp(p x,p y)
{
	return x.end<y.end;
}
int main()
{
	cin>>t;
	while(t--)
	{
		int n,ans=1;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			cin>>a[i].str>>a[i].end; 
		}
		sort(a,a+n,cmp);
		int j=0;
		for(int i=1;i<n;i++)
		{
			if(a[i].str>=a[j].end)
			{
				j=i;
				ans++;
			}			
		}
		cout<<n-ans<<endl;
	}
}
```



## 7-2

​	依然是贪心的思想，在能够跳到的格子位置，选择出能跳的最远的格子即可。

```cpp
#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],step[1000001],ans=0x3f3f3f3f;
void search(int k,int s)
{
	if(k+a[k]>=n)
	{
		ans=s+1;
		return ;
	}
	int x=k+a[k],l=0;
	for(int i=k+1;i<=k+a[k];i++)
	{
		if(a[i]>=a[x]&&a[i]+i>a[k]+k)
		{
			x=i;
		}
	}
	l=a[x]+x;
	for(int i=x;i<=k+a[k];i++)
	{
		if(a[i]+i>l)
		{
			l=a[i]+i;
			x=i;
		}
	}
	search(x,s+1);
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 	
	search(1,0);
	cout<<ans;
}
```

