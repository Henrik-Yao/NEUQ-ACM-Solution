#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int i,x,min,f[65];
    f[1]=1;f[2]=3;
    for(i=3;i<=65;i++)
    {
        min=99999999;
        for(x=1;x<i;x++)
        if(2*f[x]+pow(2,i-x)-1<min)
        min=2*f[x]+(int)pow(2,i-x)-1;
        f[i]=min;
    }
    while(cin>>n)cout<<f[n]<<endl;
    return 0;
}