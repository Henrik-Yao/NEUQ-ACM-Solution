#include<bits/stdc++.h>
using namespace std;
const int N=105,inf=1e9;
int dis[N][N],n,m;
int main()
{
    while(cin>>n>>m)
    {
        memset(dis,0,sizeof dis);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j) dis[i][j]=inf;
            }
        }
        for(int i=0;i<m;i++)
        {
            int a,b,c;
            cin>>a>>b>>c;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
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
        int minn=inf,digit=-1;
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=0;j<n;j++) temp+=dis[i][j];
            if(temp<minn) 
            {
                digit=i;
                minn=temp;
            }
        }
        cout<<digit<<endl;
    }
    return 0;
}
