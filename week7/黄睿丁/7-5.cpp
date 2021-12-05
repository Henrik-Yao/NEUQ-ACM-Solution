#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n,c;
    while(cin>>n>>c)
    {
        int weight[n+1],value[n+1];
        int i,j;
        for(i=1;i<=n;i++)
            cin>>weight[i];
        for(j=1;j<=n;j++)
            cin>>value[j];
        int va[n+1][c+1];
        for(j=0;j<=c;j++)
            for(i=0;i<=n;i++)
            {
                if(i==0||j==0)
                    va[i][j]=0;
                else if(j<weight[i])
                {
                    va[i][j]=va[i-1][j];
                }
                else
                {
                    va[i][j]=max(va[i-1][j],va[i-1][j-weight[i]]+value[i]);
                }
            }
        int maxm=-1;
            for(i=0;i<=c;i++)
        {
            maxm=max(maxm,va[n][i]);
        }
        cout<<maxm<<endl;
    }
    
}
