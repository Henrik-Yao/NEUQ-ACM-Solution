#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int t,n,c,a[100001];
int pd(int x)
{
	int now=a[1];
	int pos=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]-now>=x)
		{
			now=a[i];
			pos++;
		} 	
        if(pos>=c)
	     return 1;
	}
	return 0;
}
int main()
{
		scanf("%d%d", &n,&c);
		for(int i=1;i<=n;i++)
		{
			scanf("%d", &a[i]);
		}
		sort(a+1,a+n+1);
		int l=1;
		int r=a[n];
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(pd(mid)==1)
			{
				l=mid+1;
			}
			else
			r=mid-1;
		}
		cout<<r<<endl;
	return 0;
}
