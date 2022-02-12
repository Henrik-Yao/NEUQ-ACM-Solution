#include <bits/stdc++.h>
using  namespace  std;
#define N 10000
int main()
{
   int f[N];
   int t = 0;
    while (cin>>f[t])t++;
    sort(f,f+t);
    for(int i = 0; i < t; i++)
    {
        if(i==0)cout<<f[i];
        else cout<<"->"<<f[i];
    }
    cout<<endl;
    int t1 = 0;
    for(int i = 0; i < t; i++)
    {
        if(f[i]%2==1)
        {
            if(t1==0)cout<<f[i];
            else cout<<"->"<<f[i];
            t1++;
        }
    }
    cout<<endl;
    t1 = 0;
    for(int i = 0; i < t; i++)
    {
        if(f[i]%2==0)
        {
            if(t1==0)cout<<f[i];
            else cout<<"->"<<f[i];
            t1++;
        }
    }
    return  0;
}