#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,a[100];
	while(cin>>n)
	{
	    for(int i=0;i<n;i++)
	    {
		    cin>>a[i];
        }
        for(int i=1;i<n;i++)
        {
    	    int temp=a[i],j;
    	    for(j=i-1;temp<a[j]&&j>=0;j--)
    	    {
    		    a[j+1]=a[j];
		    }
		    a[j+1]=temp;
		    for(int k=0;k<n-1;k++)
		    {
			    cout<<a[k]<<" ";
		    }
		    cout<<a[n-1]<<endl;
	    }
	}
	return 0;
}
