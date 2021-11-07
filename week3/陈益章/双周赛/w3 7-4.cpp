#include<iostream>
using namespace std;
int main()
{
    int n,i,k;
    float fu[66],g[66];
    fu[1]=2.0;
    for(i=2;i<=64;i++)fu[i]=fu[i-1]*2.0;
    for(i=1;i<=64;i++)fu[i]-=1.0;
    g[1]=1;
    for(i=2;i<=64;i++)
    {
        g[i]=g[i-1]*2+fu[1];
        for(k=2;k<i;k++)
        {
            float temp=g[i-k]*2+fu[k];
            if(g[i]>temp)g[i]=temp;
        }
    }
    while(cin>>n)
    {
        cout<<g[n]<<endl;
    }
}
//动态规划，转移是g[n]=min{g[n-k]+g[n-k]+f[k]}(1<=k<n)其中f[n]是三个柱子时候的汉诺塔
//f[n]=f[n-1]+f[n-1]+1;----->f[n]=2^n-1;
