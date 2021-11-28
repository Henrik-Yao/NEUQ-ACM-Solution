#include<bits/stdc++.h>
using namespace std;
int f[10010],a[10010];
int main()
{
	int n;
	int t;
	cin>>t;
	while(t--)
	{
		cin>>n;
		memset(a,0,sizeof(a));
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			f[i]=0x7fffffff;
		}
		f[1]=a[1];
		int len=1;
		for(int i=2;i<=n;i++)
		{
			int l=0,r=len,mid;
			if(a[i]>f[len])f[++len]=a[i];
			else 
			{
			while(l<r)
			{	
			    mid=(l+r)/2;
			    if(f[mid]>a[i])r=mid;
				else l=mid+1; 
			}
			f[l]=min(a[i],f[l]);
     		}
   	 	}
    	if(t>0)
		{
			cout<<len<<endl<<endl;
		}
		else
		{
			cout<<len;
		}
	}

}
