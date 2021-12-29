#include<bits/stdc++.h>
using namespace std;
int a[101][101],len[101];
int main()
{
    int n,e,x,y,z;
    while (cin>>n>>e)
    {
        memset(len,0,sizeof(len));
        memset(a,0x3f,sizeof(a));
        for(int i=0;i<e;i++)
        {
            cin>>x>>y>>z;
            a[x][y]=z;
            a[y][x]=z;
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                    if(a[i][j]>a[i][k]+a[k][j])
                        a[i][j]=a[i][k]+a[k][j];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(i!=j) len[i]=len[i]+a[i][j];
        int ans=99999999,p=0;
        for(int i=0;i<n;i++)
        {
            if(len[i]<ans)
            {
                ans=len[i];
                p=i;
            }
        }
        cout<<p<<"\n";
    }
    
    return 0;
}