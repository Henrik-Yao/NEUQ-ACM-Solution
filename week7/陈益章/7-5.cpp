#include<iostream>
#include<cstring>
using namespace std;
int value[405][1505],w[405],v[405],mmax=0;
int main()
{
    int n,c;
    while(cin>>n>>c)
    {
        memset(value,0,sizeof(value));
        for(int i=1;i<=n;i++)
            cin>>w[i];
        for(int i=1;i<=n;i++)
            cin>>v[i];
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=c;j++)
            {
                if(j<w[i]) value[i][j]=value[i-1][j];
                else value[i][j]=max(value[i-1][j],value[i-1][j-w[i]]+v[i]);
                mmax=max(value[i][j],mmax);
            }
        }
        cout<<mmax<<endl;
    }
}
