#include <bits/stdc++.h>
using namespace std;
struct lu
{
    int x;
    int y;
};
bool ff[100005];
int main()
{
    int m,n;
    cin>>n;
    cin>>m;
    lu a[m+1];
    int i;
    for(i=1;i<=m;i++)cin>>a[i].x>>a[i].y;
    int k;
    cin>>k;
    int f;
    int np;
    for(i=1;i<=k;i++)
    {
        f=1;
        ff[100005]={0};
        memset(ff, 0, sizeof(bool)*100005);
        cin>>np;
        int j;
        int v;
        for(j=0;j<np;j++)
        {
            cin>>v;
            ff[v]=1;
        }
        for(int i=1;i<=m;i++)
        {
            if(ff[a[i].x]==false&&ff[a[i].y]==false)
            {
                f=false;
                break;
            }
        }
        if(f==false)cout<<"NO\n";
        else cout<<"YES\n";
        
        
    }
    return 0;
}