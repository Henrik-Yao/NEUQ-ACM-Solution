#include <bits/stdc++.h>
using namespace std;
struct ss
    {
        int x;
        char m[100];
    }d[100000];
int main()
{
    int n,m;
    cin>>n>>m;
    int xx=1;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>d[i].x>>d[i].m;
    }
    for(i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
       
        if(a==d[xx].x)
        {
            xx=xx-b;
        }
        else if(a!=d[xx].x)
        {
            xx=xx+b;
        }
        if(xx>n)xx%=n;
        else while(xx<=0)xx+=n;
        
    }
    cout<<d[xx].m;
    return 0;
}