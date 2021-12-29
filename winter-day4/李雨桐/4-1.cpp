#include <bits/stdc++.h>
using namespace std;

int Map[105][105];

int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        memset(Map,0x3f,sizeof Map);
        for(int i=1;i<=e;i++)
        {
            int from,to,v;
            cin>>from>>to>>v;
            from++,to++;
            if(from==to)
                Map[from][to]=0;
            else
            {
                Map[from][to]=v;
                Map[to][from]=v;
            }
        }

        for(int k=1;k<=n;k++)
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)
                    if(Map[i][j]>Map[i][k]+Map[k][j])
                        Map[i][j]=Map[i][k]+Map[k][j];

        long long dis[105] = {0};
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    dis[i] = dis[i] + (long long)Map[i][j];

        long long ans = 0x3f3f3f3f;
        int pos=1;
        for(int i=1;i<=n;i++)
            if(dis[i]<ans)
            {
                ans=dis[i];
                pos = i;
            }

        pos--;
        cout<<pos<<endl;
    }

    return 0;
}
