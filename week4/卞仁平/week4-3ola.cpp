#include <bits/stdc++.h>
using namespace std;
//欧拉筛
#define max 10000001
int a[max];
bool is[max];
int f;
void ola(int n)
{
    memset(is,1,sizeof(is));
    is[0]=0;is[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(is[i])
        a[f++]=i;
        for(int j=0;j<f&&i*a[j]<=n;j++)
        {
            is[i*a[j]]=0;
            if(i%a[j]==0)
            break;
        }
    }
}
int main()
{
    int n;
    cin>>n;
    ola(n);
    cout<<f;
    return 0;
}