#include <bits/stdc++.h>
using namespace std;
int prime[9999], vis[10100], a, b, cnt;
int main(void)
{
	while(cin>>a>>b)
	{
		memset(prime, 0, cnt);
		memset(vis, 0, 10010);
        cnt=0;
		
		for(int i=2; i<=b; i++)
		{
			if(!vis[i])
				prime[cnt++]=i;
			for(int j=0; j<cnt; j++)
			{
				if(i*prime[j]>b)
					break;
				vis[i*prime[j]]=1;
				if(i%prime[j]==0)
                    break;
			}
		}

        for(int i=0; i<cnt; i++)
        	if(prime[i]>=a)
            {
                cout<<prime[i];
                if((i+1)!=cnt)
                    cout<<' ';
            }
            cout<<endl;
	}
	
	return 0;
}