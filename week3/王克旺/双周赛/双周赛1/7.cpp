#include<iostream>
using namespace std;
int a[1000010],b[1000010];
long long sum=0;
void mergesort(int l,int r)
{
	if(l>=r)
    { 
	    return;
	}      
    int middle=(l+r)/2;
    mergesort(l,middle);
    mergesort(middle+1,r);
	int i=0,j,k=0,left=l,right=middle+1;
	while(left<=middle&&right<=r)
	{
	    if(a[left]<=a[right]) 
	    {
	        b[i++]=a[left++];
	    }
	    else 
		{
		    sum=sum+middle-left+1;
			b[i++]=a[right++];
		}
	}
	while(left<=middle) 
	{
	    b[i++]=a[left++];
	}
	while(right<=r) 
	{
	    b[i++]=a[right++];
	}	    
	for(j=l;j<=r;j++)
	{
	   	a[j]=b[k++];
	}
	return;
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
    cout<<sum<<endl;
}
