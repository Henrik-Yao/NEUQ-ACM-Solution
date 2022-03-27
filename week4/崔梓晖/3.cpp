#include <bits/stdc++.h>
using namespace std;
long long a;
bool vis[10000001];
int main()
{
	while(cin>>a)
	{
		long long ans=0;
		memset(vis,0,sizeof(0));
	    vis[1]=vis[0]=true;
	    for(long long i=2;i<=a;i++)
	    {
	    	if(vis[i]==false)
	    	{
	    		for(long long j=i*i;j<=a;j+=i)
	    		{
	    			vis[j]=true;
	    			
				}
			}
 	    }
		 	for(long long i=2;i<=a;i++)
			 {
			 	if(vis[i]==false)
			 	ans++;
			 }
			 cout<<ans;
			 cout<<endl;
	}  
    return 0;
}
