#include<bits/stdc++.h>
#define int long long 
using namespace std;
int n;
signed main()
{
	while(cin>>n)
	{
		int a[200];
		memset(a,0,sizeof(a));
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int i,j,k=n;
		for(i=1;i<k;i++)
		{
		    if(a[i]<a[i-1])
		    {
		        int temp=a[i];
		        for(j=i-1;j>=0 && a[j]>temp;j--)
		        {
		               a[j+1]=a[j];
		        }
		        a[j+1]=temp;
		        
		    }
			for(int t=0;t<n-1;t++)
			 {
								cout<<a[t]<<" ";
							}
							cout<<a[n-1];
							cout<<endl;
		}
	}

}
