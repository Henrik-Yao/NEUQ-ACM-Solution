#include<bits/stdc++.h>
using namespace std;
int n,m,a[100000];
int b(int dis)
{
	int num=1,t=a[0]+dis;
    for(int i=1;i<n;i++)
    {
        if(a[i]<t)
		{
			continue;
		}
        num++;
        t=a[i]+dis;
    }
    if(num>=m)
	{
		return 1;
	}
    else
	{
		return 0;
	}
}
int main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	sort(a,a+n);
	int start=0,end=a[n-1]-a[0],mid;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(b(mid))
		{
			start=mid+1;
		}
        else
		{
			end=mid-1;
		}
    }
    cout<<end;
	return 0;
}
