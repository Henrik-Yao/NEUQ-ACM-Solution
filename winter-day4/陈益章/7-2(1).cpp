#include<iostream>
#include<cstring>
using namespace std;
int router[202][202];
int main()
{
    int n,m;
    while(cin>>n>>m)
    {
        memset(router,0x3f,sizeof(router));
        for(int o=0;o<n;o++)
        {
            int x,k,y;
            cin>>x>>k;
            for(int i=0;i<k;i++)
            {
                cin>>y;
                router[x][y]=1; 
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                for(int k=0;k<n;k++)
                {
                    if(router[i][j]==1) break;
                    if(router[i][j]>router[i][k]+router[k][j])
                        router[i][j]=router[i][k]+router[k][j];
                }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin>>x>>y;
            if(router[x][y]>100) cout<<"connection impossible\n";
            else cout<<router[x][y]<<endl;
        }
    }
}
