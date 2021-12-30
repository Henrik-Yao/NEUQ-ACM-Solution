#include<bits/stdc++.h>
using namespace std;
const int inf=1e9;
int n,m,dis[205][205];
int main()
{
    while(cin>>n>>m)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j) dis[i][j]=inf;
                else dis[i][j]=0;
            }
        }
        int x;
        for(int i=0;i<n;i++)
        {
            cin>>x;
            cin>>x;
            int num;
            for(int j=0;j<x;j++)
            {
                cin>>num;
                dis[i][num]=1;
            }
        }
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            if(dis[a][b]>=inf) printf("connection impossible\n");
            else printf("%d\n",dis[a][b]);
        }
    }
    return 0;
}
