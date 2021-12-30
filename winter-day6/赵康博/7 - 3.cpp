#include<bits/stdc++.h>
using namespace std;
#define N 100

int main()
{
    int n;
    cin>>n;
    int v[51];
    memset(v,0,sizeof (v));
    for(int i = 0; i < n; i++)
    {
        int t;
        cin>>t;
        v[t]++;
    }
    for(int i = 0; i < 51; i++)
    {
        if(v[i]!=0)
        {
            cout<<i<<":"<<v[i]<<endl;
        }
    }
    return 0;
}
