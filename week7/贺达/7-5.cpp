#include<bits/stdc++.h>
using namespace std;


int main()
{
    int n,c;
    while(cin>>n,cin>>c)
    {
        int w[n+1]={0};
        int v[n+1]={0};
        int f[n+1][c+1];
        memset(f,0,sizeof(f));
        for(int i=1;i<=n;i++) cin>>w[i];

        for(int i=1;i<=n;i++) cin>>v[i];

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=c;j++)
            {

                if(j>=w[i])
                {
                    f[i][j]=max(f[i-1][j],f[i-1][j-w[i]]+v[i]);
                }
                else
                {
                    f[i][j]=f[i-1][j];
                }
            }
        }
        int r=0;
        for(int i=1;i<=c;i++) r=max(r,f[n][i]);
        cout<<r<<endl;
    }
    return 0;
}
