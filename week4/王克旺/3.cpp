#include<iostream>
#include<cmath>
using namespace std;
int prime[10000001]={0},flag[10000001]={0};
int main()
{
    int n,i,j,count=0;
    cin>>n;
    for(i=2;i<=n;i++)
    {
    	if(flag[i]==0)
    	{
    		count++;
    		prime[count]=i;
		}
		for(j=1;j<=count&&i*prime[j]<=n;j++)
		{
			flag[i*prime[j]]=1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
	cout<<count;
	return 0; 
}
