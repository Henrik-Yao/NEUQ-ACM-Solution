#include <bits/stdc++.h>
using namespace std;
int f;
bool is[10000005];
//方法二：埃氏筛没过
void aishi(int n);
signed main()
{
    int n;
    cin>>n;
    aishi(n);
    cout<<f;
    return 0;
}
void aishi(int n)
{
    memset(is,1,sizeof(is));
    is[0]=0;is[1]=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=2;i*j<=n;j++)
        is[i*j]=0;
    
        if(is[i])
        f++;
    }
}