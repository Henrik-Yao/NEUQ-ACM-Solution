#include <iostream>
using namespace std;
int a[1000001];
int b[1000001];
int c[1000001];
int d[1000001];
int e[1000001];

int main()
{
    int n;
    cin>>n;
    int i;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(b[a[i]]==0)
        {
            c[i]=c[i-1]+1;
            b[a[i]]=1;
        }
        else
            c[i]=c[i-1];
    }
    for(i=n;i>=1;i--)
    {
        if(d[a[i]]==0)
        {
            e[i]=e[i+1]+1;
            d[a[i]]=1;
        }
        else
            e[i]=e[i+1];
    }
    int s=0,m=0;
    for(i=1;i<=n;i++)
    {
        s=c[i]+e[i+1];
        m=max(s,m);
    }
    cout<<m;
}
