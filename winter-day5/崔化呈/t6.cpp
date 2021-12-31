#include<bits/stdc++.h> 
using namespace std;
int main()
{
	int n,m,x,a[110];
	while(~scanf("%d",&n))
	{
		fill(a,a+110,0);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(int i=0;i<n-1;i++)
		{
			printf("%d ",a[i]);
		}
		printf("%d\n",a[n-1]);
		scanf("%d",&m);
		while(m--)
		{
			scanf("%d",&x);
			int l=0,r=n-1,cnt=0;
			bool f=0;
			int ans[110];
			while(l<=r)
			{
				int mid=(l+r)/2;
				if(a[mid]>x){r=mid-1;}
				else if(a[mid]<x){l=mid+1;}
				else
				{
					f=1;
					if(m){printf("%d ",mid+1);}
					else{printf("%d",mid+1);}
					break;
				}
			}
			if(f==0)
			{
				if(m){printf("%d ",0);}
				else{printf("%d",0);}
			}
		}
		printf("\n");
	}
	return 0;
}
