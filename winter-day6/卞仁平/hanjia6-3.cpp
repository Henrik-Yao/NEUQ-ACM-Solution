#include <bits/stdc++.h>

using namespace std;

int main ()
{
    int n,t;
    cin>>n;
    int a[10000];
    for(int i=0;i<10000;i++) a[i]=0;
    for(int i=0;i<n;i++)
    {
        cin>>t;
        a[t]++;
    }
    for(int i=0;i<10000;i++)
    {
        if(a[i]!=0)
        {
            cout<<i<<":"<<a[i]<<endl;
        }
    }
    return 0;
}
