#include <bits/stdc++.h>
using namespace std;
int n,m,k,l;
const int X[8]={-1,-1,-1,0,1,1,1,0};
const int Y[8]={1,0,-1,-1,-1,0,1,1};
int ditu[25][25];
int dj[25][25];
void dianji(int a,int b)
{
    int c=0;
    for(int i=0;i<8;++i)
    {
        int n1=a+X[i];
        int n2=b+Y[i];
        if(n1<1||n2<1||n1>n||n2>m)
        continue;
        if(ditu[n1][n2])
        ++c;
    }
    dj[a][b]=c;
    if(c)return;
    for(int i=0;i<8;++i)
    {
        int n1=a+X[i];
        int n2=b+Y[i];
        if(n1<1||n2<1||n1>n||n2>m)
        continue;
        if(ditu[n1][n2]||dj[n1][n2]!=-1)
        continue;
        dianji(n1,n2);
    }
}


int main()
{
    
    
    cin>>n>>m>>k>>l;
    for(int i=1;i<=k;i++)
    {
        int x,y;
        cin>>x>>y;
        ++x;
        ++y;
        ditu[x][y]=1;
    }
    memset(dj,-1,sizeof(dj));
    for(int i=1;i<=l;i++)
    {
        int o,p;
        cin>>o>>p;
        ++o;
        ++p;
        if(dj[o][p]!=-1)
        continue;
        if(ditu[o][p])
        {
            puts("You lose");
            return 0;
        }
        dianji(o,p);
        
        for(int j=1;j<=n;++j,puts(""))
        {
            for(int t=1;t<=m;++t)
            {
                cout<<dj[j][t]<<" ";
            }
        }
        int f=1;
        for(int j=1;j<=n;++j)
        {
            for(int t=1;t<=m;++t)
            {
                if(dj[j][t]==-1&&!ditu[j][t])
                f=0;
            }
        }
        if(f)
        {
            puts("You win");
            return 0;
        }
        puts("");
    }
    return 0;
}
