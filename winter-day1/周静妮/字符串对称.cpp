#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,m,k,i,j,t=1;
	int a[1000]={0};
	cin>>n>>m>>k;
	for(i=0;i<n;i++)
	{
		if(i%2==0)
		{
			while(a[t]) 
            {
                t++;
                if(t>n) t=1;
            }
            t++;
			for(j=0;j<m;j++)
			{
				t--;
				if(t==0) t=n;
				if(a[t]) 	j--;			
			}
			a[t]=1;
			cout<<t<<' ';
		}
		else
		{
			while(a[t])
            {
                 t--;
                if(t==0) t=n;
            }
            t--;
			for(j=0;j<k;j++)
			{
				t++;	
				if(t>n) t=1;
				if(a[t]) 	j--;			
			}
			a[t]=1;
			cout<<t<<' ';
		}
	}
    cout<<endl;
	return 0;
 } 
