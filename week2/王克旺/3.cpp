#include<bits/stdc++.h>
using namespace std;
int a[100010],t[100010];
void mergesort(int start,int end)
{
    if(start>=end)
	{
	    return;
	}
	else
	{
   	    int middle;
	    middle=(start+end)/2;
	    mergesort(start,middle);
	    mergesort(middle+1,end);
	    int i=0,j,k=0,left=start,right=middle+1;
	    while(left<=middle&&right<=end)
	    {
		    if(a[left]<a[right]) 
		    {
		        t[i]=a[left];
		        left++;
		        i++;
		    }
		    else 
			{
			    t[i]=a[right];
			    right++;
			    i++;
			}
	    }
	    while(left<=middle) 
	    {
	        t[i]=a[left];
	        left++;
	        i++;
	    }
	    while(right<=end) 
	    {
	        t[i]=a[right];
	        right++;
	        i++;
	    }
	    
	    for(j=start;j<=end;j++)
	    {
	    	a[j]=t[k];
	    	k++;
	    }
    }
}
int main()
{
	int n,i;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	mergesort(0,n-1);
	for(i=0;i<n;i++)
	{
	    cout<<a[i]<<" ";
	}
}
