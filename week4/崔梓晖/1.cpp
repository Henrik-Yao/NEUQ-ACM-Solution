#include <bits/stdc++.h>
using namespace std;
int a,b;
int vis[10001];
int main()
{
	while(cin>>a>>b)
	{
		int t=1,pos=0;
		memset(vis,0,sizeof(0));
	    vis[1]=vis[0]=1;
	    for(int i=2;i<=10000;i++)
	    {
	    	if(vis[i]==0)
	    	{
	    		for(int j=i*i;j<=b;j+=i)
	    		{
	    			vis[j]=1;
				}
			}
 	    }
 	    for(int i=a;i<=b;i++)
 	    {
 	    	if(vis[i]==0)
 	    	{
 	    		pos=i;
			}		
		}
		 	for(int i=a;i<=b;i++)
			 {
			 	if(i==pos)
			 	{
			 	cout<<pos;
			 	break;
			    }
			 	if(vis[i]==0)
			 	{
			 	cout<<i<<" ";
			    }
			 }
			 cout<<endl;
	}  
    return 0;
}
