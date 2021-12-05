#include<iostream>
using namespace std;
int f[10005],a[1050];
int main()
{
    int t,n,ans,tot=0;
    cin>>t;
    while(t--)
    {
        ans=0;    tot++;
        cin>>n;
        for(int i=1;i<=n;i++)
        {          
            cin>>a[i];
            f[i]=1;            
         }
        for(int i=2;i<=n;i++)
        {
            for(int j=1;j<i;j++)
            {
                if(a[i]>a[j])
                f[i]=max(f[i],f[j]+1);
            }
            ans=max(ans,f[i]);
        }
        if(tot==1)
        cout<<ans;
        else cout<<endl<<endl<<ans;
    }
}

