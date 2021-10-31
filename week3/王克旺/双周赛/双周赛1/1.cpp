#include<iostream>
using namespace std;
int zuida(int a[],int left,int right)
{
	if(left==right)
	{
		return a[left];
	}
	else
	{
	    int middle=(left+right)/2;
	    int leftzuida,rightzuida;
	    leftzuida=zuida(a,left,middle);
	    rightzuida=zuida(a,middle+1,right);
        int l=0,r=0,t=0;
        for(int i=middle;i>=left;i--)
        {
            t=t+a[i];
            if(t>l)
            {
            	l=t;
    		}
    	}
    	t=0;
    	for(int i=middle+1;i<=right;i++)
    	{
    		t=t+a[i];
    		if(t>r)
    		{
    			r=t;
    		}
    	}
       	int max=l+r;
    	if(leftzuida>max)
    	{
    		max=leftzuida;
    	}
    	else if(rightzuida>max)
    	{
    		max=rightzuida;
    	}
    	return max;
    }
}
int main()
{
	int n,i,count=0;
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<0)
		{
			count++;
		}
	}
	if(count==n)
	{
		cout<<0;
	}
	else
	{
		cout<<zuida(a,0,n-1);
	}
	return 0;
}
