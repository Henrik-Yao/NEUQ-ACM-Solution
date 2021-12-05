#include <bits/stdc++.h>
using namespace std;
const int N=1010;
int n,c;
int main()
{
    //while(~scanf("%d %d",n,c))
    while(cin>>n>>c)
    {
        int w[N],v[N];
        for(int i=1;i<=n;i++)
        cin>>w[i];
        for(int i=1;i<=n;i++)
        cin>>v[i];
        int f[N][N];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<=c;j++)
            {
                f[i][j]=f[i-1][j];
                if(j>=w[i])
                f[i][j]=max(f[i][j],f[i-1][j-w[i]]+v[i]);
            }
        }
        int ans=0;
        for(int i=0;i<=c;i++)
        ans=max(ans,f[n][i]);
        cout<<ans<<endl;
    }
    return 0;
}