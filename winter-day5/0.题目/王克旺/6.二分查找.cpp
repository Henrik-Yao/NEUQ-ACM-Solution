#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	while(cin>>n)
	{
		int m,a[100],b[100],ans[100];
		memset(ans,0,sizeof(ans));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		cin>>m;
		for(int i=0;i<m;i++)
		{
			cin>>b[i];
		}
		sort(a,a+n);
		for(int i=0;i<n-1;i++)
		{
			cout<<a[i]<<" ";
		}
		cout<<a[n-1]<<endl;
		for(int i=0;i<m;i++)
		{
			int start=0,end=n-1;
			while(start<=end)
	    	{
			    int mid=(start+end)/2;
			    if(a[mid]>b[i])
			    {
			    	end=mid-1;
			    }
			    else if(a[mid]<b[i])
			    {
			    	start=mid+1;
			    }
			    else
			    {
			    	ans[i]=mid+1;
			    	break;
	    		}
	    	}
		}		
		for(int i=0;i<m-1;i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<ans[m-1]<<endl;
	}
	return 0;
}
