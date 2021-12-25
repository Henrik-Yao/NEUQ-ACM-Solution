#include<iostream>
using namespace std;
void sort(int a[],int n)
{
    int i,j;
	for(i=1;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            if(a[j]>a[j+1])
            {
                swap(a[j],a[j+1]);
            }
        }
    }
}
int main()
{
    int n,m,i,j=0,length;
    int a[1000],b[1000];
    cin>>n>>m;
    if(n<=m)
    {
    	length=n;
	}
	else
	{
		for(i=0;i<n;i++)
        {
            cin>>a[i];
        }
        for(i=1;i<n;i++)
        {
            for(j=0;j<n-i;j++)
            {
                if(a[j]>a[j+1])
                {
                    swap(a[j],a[j+1]);
                }
            }
        }
    	length=a[n-1]-a[0]+1;
        for(i=0;i<n-1;i++)
        {
            b[i]=a[i+1]-a[i]-1;
        }
        for(i=1;i<n-1;i++)
        {
            for(j=0;j<n-1-i;j++)
            {
                if(b[j]>b[j+1])
                {
                    swap(b[j],b[j+1]);
                }
            }
        }
		j=n-2; 
        for(i=1;i<m;i++)
        {
            length=length-b[j];
            j--;
        }
	}
    cout<<length;
    return 0;
}
