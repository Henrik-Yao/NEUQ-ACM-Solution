#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int w[2005],v[2005];
int f[2005],ans,n,c;
int main()
{
    while(cin>>n>>c)
    {
        memset(f,0,sizeof(f));ans=0;
        for(int i=1;i<=n;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
            for(int j=c;j>=w[i];j--)
            {
                f[j]=max(f[j],f[j-w[i]]+v[i]);
                ans=max(ans,f[j]);
            }
        cout<<ans<<endl;
    }
}
