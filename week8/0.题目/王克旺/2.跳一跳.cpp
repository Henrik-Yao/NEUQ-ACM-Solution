#include<iostream>
using namespace std;
int a[1000000];
int main()
{
	int t,i,j,k=0,m,count=0;
	cin>>t;
	for(i=0;i<t;i++)
	{
		cin>>a[i];
	}
    j=0+a[0];
    m=0+a[0];
    if(m>=t-1)
    {
    	count=1;
	}
	else
	{
        for(i=1;i<t;i++)
        {
            if(i+a[i]>m)
            {
                k=i;
                m=i+a[i];
                if(m>=t-1)
				{
					count=count+2;
                    break;
				}              
            }
            if(i==j)
            {
                j=k+a[k];
                i=k;
                count++;
            }
        }
    }
    cout<<count;
    return 0;
}
