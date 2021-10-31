#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int a[m][2];
    int b[n+1];
    for(int i=0;i<m;i++)
    {
        cin>>a[i][0]>>a[i][1];
    }
    int k;
    cin>>k;
    int c[k];
    for(int l=0;l<k;l++)
    {
        int np;
        cin>>np;
        int v;
        for(int i=1;i<=n;i++)
        {
            b[i]=1;
        }
        for(int i=0;i<np;i++)
        {
            cin>>v;
            b[v]=0;

        }
        int t=1;
        for(int i=0;i<m;i++)
        {
            if(b[a[i][0]]==1&&b[a[i][1]]==1)
            {
                t=0;
            }
        }
        if(t==0)
            c[l]=0;
            else c[l]=1;
    }
    for(int i=0;i<k;i++)
    {
        if(c[i]==0)
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
