# Day4

---

## 7-1 相邻数对

排序后直接看相邻的两个数是否相差1。

```
#include<bits/stdc++.h>
using namespace std;
int a[1010];

int main()
{
    int n,cnt=0;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=1;i<n;i++)
        if(a[i]-a[i-1]==1)
            cnt++;
    cout<<cnt;
    return 0;
}
```



## 7-3 两个有序序列的中位数

可恶，集合居然不要去重555

```
#include<bits/stdc++.h>
using namespace std;

int a[200001];
int main()
{
    int n;
    cin>>n;
    for(int i=0;i<2*n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+2*n);
    cout<<(a[n-1]+a[n])/2<<endl;
    return 0;
}
```



## 7-4 二分查找

打板

```
#include<bits/stdc++.h>
using namespace std;
int a[1001],cnt=0,n;
int Binary(int a[],int x)
{
    int l=0,r=n-1,flag=0,mid;
    while(l<=r)
    {
        cnt++;
        int mid=(l+r)>>1;
        if(a[mid]<=x)
        {
            if(a[mid]==x) return mid;
            else l=mid+1;
        }
        else r=mid-1;
    }
    return -1;
}

int main()
{
    int x;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cin>>x;
    sort(a,a+n);
    cout<<Binary(a,x)<<endl;
    cout<<cnt;
    return 0;
}
```



## 7-6 二分查找

打板

```
#include<bits/stdc++.h>
using namespace std;
int a[101],n,m;
int BinarySearch(int a[],int x)
{
    int l=1,r=n,mid;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(a[mid]<=x)
        {
            if(a[mid]==x) return mid;
            else l=mid+1;
        }
        else r=mid-1;
    }
    return 0;
}
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        cin>>a[i];
        sort(a+1,a+n+1);
        for(int i=1;i<=n;i++)
        {
            if(i==n)
                cout<<a[i]<<endl;
            else
                cout<<a[i]<<' ';
        }
        cin>>m;
        for(int i=1;i<=m;i++)
        {
            int x;
            cin>>x;
            if(i==m)
                cout<<BinarySearch(a,x)<<endl;
            else
                cout<<BinarySearch(a,x)<<' ';
        }
    }
    return 0;
}
```



## 7-7愤怒的牛

二分答案

```
#include<bits/stdc++.h>
using namespace std;
int a[100001];
int n,m,i;
bool check(int t)
{
	int cnt=m-1;
	int now=0;
	for(i=1;i<n;i++)
	{
		if(a[i]-a[now]>=t)
		{
			now=i;
			cnt--;
			if(cnt==0)
			break;
		}
	}
	//cout<<"t:"<<t<<" cnt:"<<cnt<<endl;
	if(cnt)
		return false;
	else
		return true;
}

int main()
{
	cin>>n>>m;
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	sort(a,a+n);
	/*for(i=0;i<n;i++)
		cout<<a[i]<<' ';
	cout<<endl;*/
	int l=1,r=a[n-1]-a[0];
	int ans;
	while(l<=r)
	{
		//cout<<"left"<<l<<' '<<"right"<<r<<endl;
		int mid=(l+r)>>1;
		if(check(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else
			r=mid-1;
	}
	cout<<ans;
	return 0;
}
```

