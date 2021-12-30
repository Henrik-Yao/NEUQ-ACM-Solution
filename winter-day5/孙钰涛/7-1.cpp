#include<bits/stdc++.h>
using namespace std;
bool a[10001];
int main()
{
    memset(a,0,sizeof(a));
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(a[x]==0) a[x]=1;
    }
    x=0;
    for(int i=1;i<=10000;i++)
        if(a[i]==1 && a[i-1]==1) x++;
    cout<<x;
    return 0;
}