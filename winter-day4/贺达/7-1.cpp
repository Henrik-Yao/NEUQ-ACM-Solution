#include<bits/stdc++.h>
using namespace std;
#define M 110
int a[110][110];
long long sum[110];
int main()
{
    int n,e;
    while(cin>>n>>e)
    {
        //建立邻接矩阵
        memset(a ,0x3f, sizeof a);//
        for(int i=1;i<=e;i++)
        {
            int from,to,val;
            cin>>from>>to>>val;
            if(from!=to)
            {
                a[from][to]=val;
                a[to][from]=val;
            }
            else
            {
                a[from][to]=0;
            }
        }
        //floyed暴力枚举
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(a[i][j]>a[i][k]+a[k][j])
                    {
                          a[i][j]=a[i][k]+a[k][j];
                    }
                }
            }
        }
        memset(sum,0,sizeof sum);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i!=j)
                {
                    sum[i]=sum[i]+(long long)a[i][j];
                }
            }
        }

        long long mi=0x3f3f3f3f;
        int loca=0;
        for(int i=0;i<n;i++)
        {
             if(sum[i]<mi)
              {
                  mi=sum[i];
                  loca = i;
              }
        }
      
        cout<<loca;
        cout<<endl;
    }
    return 0;
}
