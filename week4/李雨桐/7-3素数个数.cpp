#include <bits/stdc++.h>

using namespace std;


bool vis[10000005];
int ans=0;

void prime(int n) //0表示是素数，1表示不是素数
{
    for(int i=2;i<=n;i++)
	    vis[i]=0;

    vis[0]=1;
    vis[1]=1;
    for(int i=2;i<=sqrt(n);i++)
    {
        if(!vis[i])
        {
            for(int j=i*i;j<=n;j+=i)
            {
                vis[j]=1;
            }
        }
    }

}

int main()
{
    int n;
    cin>>n;

    prime(n);
    for(int k=2;k<=n;k++)
    {
        if(vis[k]==0)
            ans++;
    }
    cout<<ans<<endl;

    return 0;
}
